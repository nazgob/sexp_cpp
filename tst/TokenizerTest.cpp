#include <gtest/gtest.h>

#include "Data.hpp"
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
    std::list<std::string> list = Data::CreateList("()");

    EXPECT_EQ("(", list.front());
    EXPECT_EQ(")", list.back());
    EXPECT_EQ(static_cast<size_t>(2), list.size());
  }

  TEST(TokenizerTest, EmptyListWithSpaces)
  {
    std::list<std::string> list = Data::CreateList(" ( ) ");

    EXPECT_EQ("(", list.front());
    EXPECT_EQ(")", list.back());
    EXPECT_EQ(static_cast<size_t>(2), list.size());
  }

  TEST(TokenizerTest, Integer)
  {
    std::list<std::string> list = Data::CreateList("123");

    EXPECT_EQ("123", list.front());
    EXPECT_EQ(static_cast<size_t>(1), list.size());
  }

  TEST(TokenizerTest, SimpleSExp)
  {
    std::list<std::string> list = Data::CreateList("( + 2 3 )");

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
    std::list<std::string> list = Data::CreateList("( + 1 ( - 4 5 ) )");

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
  
  TEST(TokenizerTest, ListWithTwoQuotes)
  {
    std::list<std::string> list = Data::CreateList("(if #f (quote a) (quote b))");

    EXPECT_EQ(static_cast<size_t>(12), list.size());
    EXPECT_EQ("(", list.front()); list.pop_front();
    EXPECT_EQ("if", list.front()); list.pop_front();
    EXPECT_EQ("#f", list.front()); list.pop_front();
    EXPECT_EQ("(", list.front()); list.pop_front();
    EXPECT_EQ("quote", list.front()); list.pop_front();
    EXPECT_EQ("a", list.front()); list.pop_front();
    EXPECT_EQ(")", list.front()); list.pop_front();
    EXPECT_EQ("(", list.front()); list.pop_front();
    EXPECT_EQ("quote", list.front()); list.pop_front();
    EXPECT_EQ("b", list.front()); list.pop_front();
    EXPECT_EQ(")", list.front()); list.pop_front();
    EXPECT_EQ(")", list.front()); list.pop_front();
    EXPECT_TRUE(list.empty());
  }
  
}

