#include <gtest/gtest.h>

#include "../src/Parser.h"
#include "../src/Utils.h"

using namespace sexp_cpp;

#include <stdexcept>

namespace
{
  TEST(ParserTest, NoTokens)
  {
    std::list<std::string> sample;
    Parser parser;
    EXPECT_THROW(parser.Parse(sample), std::invalid_argument);
  }

  TEST(ParserTest, WrongParentesisOrder)
  {
    std::list<std::string> sample;
    Parser parser;
    sample.push_back(")");
    EXPECT_THROW(parser.Parse(sample), std::invalid_argument);
  }

  TEST(ParserTest, SimpleSExpWithPlusOp)
  {
    std::list<std::string> sample;
    sample.push_back("(");
    sample.push_back("+");
    sample.push_back("2");
    sample.push_back("3");
    sample.push_back(")");

    Parser parser;
    EXPECT_EQ(5, parser.Parse(sample));
  }

  TEST(ParserTest, SimpleSExpWithMinusOp)
  {
    std::list<std::string> sample;
    sample.push_back("(");
    sample.push_back("-");
    sample.push_back("7");
    sample.push_back("5");
    sample.push_back(")");

    Parser parser;
    EXPECT_EQ(2, parser.Parse(sample));
  }
}

