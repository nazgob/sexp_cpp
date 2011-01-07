#include <gtest/gtest.h>

#include "DataFactory.hpp"
#include "../src/Reader.hpp"
#include "../src/Exp.hpp"

using namespace sexp_cpp;

#include <list>
#include <string>
#include <boost/lexical_cast.hpp>

namespace
{
  
	class ReaderTest : public ::testing::Test
	{
		protected:
      Reader reader;
	};

  TEST_F(ReaderTest, ShouldReadInteger)
  {
    std::string positive = "123";
    std::list<std::string> positiveList = DataFactory::GetList(positive);
    EXPECT_EQ(reader.Read(positiveList)->WhoAmI(), "ValueExp");

    std::string negative = "-123";
    std::list<std::string> negativeList = DataFactory::GetList(negative);
    EXPECT_EQ(reader.Read(negativeList)->WhoAmI(), "ValueExp");
  }

  TEST_F(ReaderTest, ShouldReadBoolean)
  {
    std::string sthTrue = "#t";
    std::list<std::string> trueList = DataFactory::GetList(sthTrue);
    EXPECT_EQ(reader.Read(trueList)->WhoAmI(), "BoolExp");

    std::string sthFalse = "#f";
    std::list<std::string> falseList = DataFactory::GetList(sthFalse);
    EXPECT_EQ(reader.Read(falseList)->WhoAmI(), "BoolExp");
  }

  TEST_F(ReaderTest, ShouldReadEmptyList)
  {
    std::string empty = "()";
    std::list<std::string> emptyList = DataFactory::GetList(empty);
    EXPECT_EQ(reader.Read(emptyList)->WhoAmI(), "EmptyListExp");
  }

  TEST_F(ReaderTest, ShouldReadList)
  {
    std::string simple("( 1 2 )");
    std::list<std::string> simpleList = DataFactory::GetList(simple);
    EXPECT_EQ(reader.Read(simpleList)->WhoAmI(), "PairExp");

    std::string nested = "( 1 ( 2 3 ) )";
    std::list<std::string> nestedList = DataFactory::GetList(nested);
    EXPECT_EQ(reader.Read(nestedList)->WhoAmI(), "PairExp");

    std::string variadic = "( 1 2 3 4 5 )";
    std::list<std::string> variadicList = DataFactory::GetList(variadic);
    EXPECT_EQ(reader.Read(variadicList)->WhoAmI(), "PairExp");
  }

}

