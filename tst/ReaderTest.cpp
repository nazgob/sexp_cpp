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

    pExp positiveResult = reader.Read(positiveList);
    EXPECT_EQ(positiveResult->WhoAmI(), "ValExp");
    EXPECT_EQ(positiveResult->Write(), "123");

    std::string negative = "-123";
    std::list<std::string> negativeList = DataFactory::GetList(negative);
    
    pExp negativeResult = reader.Read(negativeList);
    EXPECT_EQ(negativeResult->WhoAmI(), "ValExp");
    EXPECT_EQ(negativeResult->Write(), "-123");
  }

  TEST_F(ReaderTest, ShouldReadBoolean)
  {
    std::string sthTrue = "#t";
    std::list<std::string> trueList = DataFactory::GetList(sthTrue);

    pExp trueResult = reader.Read(trueList);
    EXPECT_EQ(trueResult->WhoAmI(), "BoolExp");
    EXPECT_EQ(trueResult->Write(), "#t");

    std::string sthFalse = "#f";
    std::list<std::string> falseList = DataFactory::GetList(sthFalse);
    
    pExp falseResult = reader.Read(falseList);
    EXPECT_EQ(falseResult->WhoAmI(), "BoolExp");
    EXPECT_EQ(falseResult->Write(), "#f");
  }
  
  TEST_F(ReaderTest, ShouldReadSymbols) // TODO: check for other allowed symbol formats
  {
    std::string symbol = "foobar";
    std::list<std::string> symbolList = DataFactory::GetList(symbol);

    pExp result = reader.Read(symbolList);
    EXPECT_EQ(result->WhoAmI(), "SymbolExp");
    EXPECT_EQ(result->Write(), "foobar");
  }

  TEST_F(ReaderTest, ShouldReadEmptyList)
  {
    std::string empty = "()";
    std::list<std::string> emptyList = DataFactory::GetList(empty);

    pExp result = reader.Read(emptyList);
    EXPECT_EQ(result->WhoAmI(), "EmptyListExp");
    EXPECT_EQ(result->Write(), "");
  }

  TEST_F(ReaderTest, ShouldReadList)
  {
    std::string simple("( 1 2 )");
    std::list<std::string> simpleList = DataFactory::GetList(simple);
    pExp simpleResult = reader.Read(simpleList);
    EXPECT_EQ(simpleResult->WhoAmI(), "PairExp");
    EXPECT_EQ(simpleResult->Write(), "1 2");

    std::string nested = "( 1 ( 2 3 ) )";
    std::list<std::string> nestedList = DataFactory::GetList(nested);
    pExp nestedResult = reader.Read(nestedList);
    EXPECT_EQ(nestedResult->WhoAmI(), "PairExp");
    EXPECT_EQ(nestedResult->Write(), "1 2 3");

    std::string variadic = "( 1 2 3 4 5 )";
    std::list<std::string> variadicList = DataFactory::GetList(variadic);
    pExp variadicResult = reader.Read(variadicList);
    EXPECT_EQ(variadicResult->WhoAmI(), "PairExp");
    EXPECT_EQ(variadicResult->Write(), "1 2 3 4 5");
  }
  
  TEST_F(ReaderTest, ShouldReadQuotedSymbol)
  {
    std::string quoted = "(quote symbol)";
    std::list<std::string> quotedList = DataFactory::GetList(quoted);
    pExp result = reader.Read(quotedList);
    EXPECT_EQ(result->WhoAmI(), "PairExp");
    EXPECT_EQ(result->Write(), "quote symbol");
  }
  
  TEST_F(ReaderTest, ShouldReadQuotedList)
  {
    std::string quoted = "(quote (1 2 3))";
    std::list<std::string> quotedList = DataFactory::GetList(quoted);
    pExp result = reader.Read(quotedList);
    EXPECT_EQ(result->WhoAmI(), "PairExp");
    EXPECT_EQ(result->Write(), "quote 1 2 3");
  }
  
  TEST_F(ReaderTest, ShouldReadSingleQuotedInteger)
  {
    std::string quoted = "'42";
    std::list<std::string> quotedList = DataFactory::GetList(quoted);
    pExp result = reader.Read(quotedList);
    EXPECT_EQ(result->WhoAmI(), "PairExp");
    EXPECT_EQ(result->Write(), "quote 42");
  }

}

