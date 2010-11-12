#include <gtest/gtest.h>

#include "../src/Lexer.h"
#include "../src/Utils.h"

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
    sample.push_back("(");
    sample.push_back("+");
    sample.push_back("2");
    sample.push_back("3");
    sample.push_back(")");

    Lexer lexer;
    EXPECT_EQ(5, lexer.Lex(sample));
    EXPECT_TRUE(sample.empty());
  }

  TEST(LexerTest, SimpleSExpWithMinusOp)
  {
    // ( - 7 5 )
    std::list<std::string> sample;
    sample.push_back("(");
    sample.push_back("-");
    sample.push_back("7");
    sample.push_back("5");
    sample.push_back(")");

    Lexer lexer;
    EXPECT_EQ(2, lexer.Lex(sample));
    EXPECT_TRUE(sample.empty());
  }
  
  TEST(LexerTest, NestedSExp)
  {
    // ( + 1 ( - 4 5 ) )
    // ( + 1 x ) where x = ( - 4 5 )

    std::list<std::string> sample;
    sample.push_back("(");
    sample.push_back("+");
    sample.push_back("1");
    sample.push_back("(");
    sample.push_back("-");
    sample.push_back("4");
    sample.push_back("5");
    sample.push_back(")");
    sample.push_back(")");

    Lexer lexer;
    EXPECT_EQ(0, lexer.Lex(sample));
    EXPECT_TRUE(sample.empty());
  }

  TEST(LexerTest, LexSubExpWithPlusOp)
  {
    // ( + 2 4 )
    std::list<std::string> sample;
    sample.push_back("(");
    sample.push_back("+");
    sample.push_back("2");
    sample.push_back("4");
    sample.push_back(")");

    Lexer lexer;
    lexer.LexSubExp(sample);
    EXPECT_EQ("6", sample.front());
    EXPECT_EQ(static_cast<size_t>(1), sample.size());
  }
  
  TEST(LexerTest, NestedSubExp)
  {
    // ( + 1 ( - 4 5 ) )
    // ( + 1 x ) where x = ( - 4 5 )

    std::list<std::string> sample;
    sample.push_back("(");
    sample.push_back("+");
    sample.push_back("1");
    sample.push_back("(");
    sample.push_back("-");
    sample.push_back("4");
    sample.push_back("5");
    sample.push_back(")");
    sample.push_back(")");

    Lexer lexer;
    lexer.LexSubExp(sample);
    EXPECT_EQ("0", sample.front());
    EXPECT_EQ(static_cast<size_t>(1), sample.size());
  }
}

