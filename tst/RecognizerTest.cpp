#include <gtest/gtest.h>

#include "DataFactory.hpp"
#include "../src/Recognizer.hpp"

using namespace sexp_cpp;

#include <list>
#include <string>
#include <boost/lexical_cast.hpp>

namespace
{
  TEST(RecognizerTest, IsInteger)
  {
    std::string positive = "123";
    std::string negative = "-123";
    EXPECT_TRUE(Recognizer::IsInteger(positive));
    EXPECT_TRUE(Recognizer::IsInteger(negative));

    std::string tooBig= "99999999999999999999";
    std::string someString = "foobar";
    EXPECT_FALSE(Recognizer::IsInteger(tooBig));
    EXPECT_FALSE(Recognizer::IsInteger(someString));
  }

  TEST(RecognizerTest, IsBoolean)
  {
    std::string sthTrue = "#t";
    std::string sthFalse = "#f";

    EXPECT_TRUE(Recognizer::IsBoolean(sthTrue));
    EXPECT_TRUE(Recognizer::IsBoolean(sthFalse));
  }

  TEST(RecognizerTest, IsEmptyList)
  {
    std::string emptyList = "()";
    std::string notEmptyList = "(2 2)";

    EXPECT_TRUE(Recognizer::IsEmptyList(emptyList));
    EXPECT_FALSE(Recognizer::IsEmptyList(notEmptyList));
  }

  TEST(RecognizerTest, IsList)
  {
    std::string simpleList("( 1 2 )");
    std::string nestedList = "( 1 ( 2 3 ) )";
    std::string variadicList = "( 1 2 3 4 5 )";
    std::string emptyList = "()";

    EXPECT_TRUE(Recognizer::IsList(DataFactory::GetList(simpleList)));
    EXPECT_TRUE(Recognizer::IsList(DataFactory::GetList(nestedList)));
    EXPECT_TRUE(Recognizer::IsList(DataFactory::GetList(variadicList)));
    EXPECT_FALSE(Recognizer::IsList(DataFactory::GetList(emptyList)));
  }

}

