#include <gtest/gtest.h>

#include "DataFactory.hpp"
#include "../src/Lexer.hpp"
#include "../src/Utils.hpp"

using namespace sexp_cpp;

#include <stdexcept>

namespace
{
  TEST(LexerTest, NoTokens)
  {
    std::list<std::string> sample;

    Lexer lexer;
    EXPECT_THROW(lexer.Lex(sample), std::invalid_argument);
  }

  TEST(LexerTest, WrongParentesisOrder)
  {
    std::list<std::string> sample;

    Lexer lexer;
    sample.push_back(")");
    EXPECT_THROW(lexer.Lex(sample), std::invalid_argument);
  }

  TEST(LexerTest, SimpleSExpWithPlusOp)
  {
    // ( + 2 3 )
    std::list<std::string> sample;
    DataFactory::FillWithSimpleSExp(sample);

    Lexer lexer;
    EXPECT_EQ(5, lexer.Lex(sample));
    EXPECT_TRUE(sample.empty());
  }

  TEST(LexerTest, NestedSExp)
  {
    // ( + 1 ( - 4 5 ) )
    // ( + 1 x ) where x = ( - 4 5 )

    std::list<std::string> sample;
    DataFactory::FillWithNestedSExp(sample);
    
    Lexer lexer;
    EXPECT_EQ(0, lexer.Lex(sample));
    EXPECT_TRUE(sample.empty());
  }

  TEST(LexerTest, LexSubExpWithPlusOp)
  {
    // ( + 2 4 )
    std::list<std::string> sample;
    DataFactory::FillWithSimpleSExp(sample);

    Lexer lexer;
    lexer.LexSubExp(sample);
    EXPECT_EQ("5", sample.front());
    EXPECT_EQ(static_cast<size_t>(1), sample.size());
  }
  
  TEST(LexerTest, NestedSubExp)
  {
    // ( + 1 ( - 4 5 ) )
    // ( + 1 x ) where x = ( - 4 5 )

    std::list<std::string> sample;
    DataFactory::FillWithNestedSExp(sample);

    Lexer lexer;
    lexer.LexSubExp(sample);
    EXPECT_EQ("0", sample.front());
    EXPECT_EQ(static_cast<size_t>(1), sample.size());
  }
}

