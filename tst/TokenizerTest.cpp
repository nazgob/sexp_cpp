#include <gtest/gtest.h>

#include "DataFactory.hpp"
#include "../src/Tokenizer.hpp"
#include "../src/Utils.hpp"

using namespace sexp_cpp;

#include <stdexcept>

namespace
{

  TEST(TokenizerTest, EmptyString)
  {
    std::string empty;
    Tokenizer tokenizer;
    EXPECT_THROW(tokenizer.Tokenize(empty), std::invalid_argument);
  }

  TEST(TokenizerTest, EmptyList)
  {
    std::string sample = "()";
    Tokenizer tokenizer;
    std::list<std::string> list = tokenizer.Tokenize(sample);
    EXPECT_EQ("(", list.front());
    EXPECT_EQ(")", list.back());
    EXPECT_EQ(static_cast<size_t>(2), list.size());
  }

  TEST(TokenizerTest, EmptyListWithSpaces)
  {
    std::string sample = " ( ) ";
    Tokenizer tokenizer;
    std::list<std::string> list = tokenizer.Tokenize(sample);
    EXPECT_EQ("(", list.front());
    EXPECT_EQ(")", list.back());
    EXPECT_EQ(static_cast<size_t>(2), list.size());
  }

  TEST(TokenizerTest, Integer)
  {
    std::string sample = "123";
    Tokenizer tokenizer;
    std::list<std::string> list = tokenizer.Tokenize(sample);
    EXPECT_EQ("123", list.front());
    EXPECT_EQ(static_cast<size_t>(1), list.size());
  }

  TEST(TokenizerTest, SimpleSExp)
  {
    // ( + 2 3 )
    std::string sample;
    DataFactory::FillWithSimpleSExp(sample);

    Tokenizer tokenizer;
    std::list<std::string> list = tokenizer.Tokenize(sample);

    EXPECT_EQ(static_cast<size_t>(5), list.size());
    EXPECT_EQ("(", list.front()); list.pop_front();
    EXPECT_EQ("+", list.front()); list.pop_front();
    EXPECT_EQ("2", list.front()); list.pop_front();
    EXPECT_EQ("3", list.front()); list.pop_front();
    EXPECT_EQ(")", list.front()); list.pop_front();
    EXPECT_TRUE(list.empty());
  }

  TEST(TokenizerTest, NestedSExp)
  {
    // ( + 1 ( - 4 5 ) )
    std::string sample;
    DataFactory::FillWithNestedSExp(sample);

    Tokenizer tokenizer;
    std::list<std::string> list = tokenizer.Tokenize(sample);

    EXPECT_EQ(static_cast<size_t>(9), list.size());
    EXPECT_EQ("(", list.front()); list.pop_front();
    EXPECT_EQ("+", list.front()); list.pop_front();
    EXPECT_EQ("1", list.front()); list.pop_front();
    EXPECT_EQ("(", list.front()); list.pop_front();
    EXPECT_EQ("-", list.front()); list.pop_front();
    EXPECT_EQ("4", list.front()); list.pop_front();
    EXPECT_EQ("5", list.front()); list.pop_front();
    EXPECT_EQ(")", list.front()); list.pop_front();
    EXPECT_EQ(")", list.front()); list.pop_front();
    EXPECT_TRUE(list.empty());
  }

}

