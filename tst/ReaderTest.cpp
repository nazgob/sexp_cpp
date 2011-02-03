#include <gtest/gtest.h>

#include "Data.hpp"
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
    std::list<std::string> positiveList = Data::CreateList("123");
    pExp positiveResult = reader.Read(positiveList);
    EXPECT_EQ(positiveResult->WhoAmI(), "ValExp");
    EXPECT_EQ(positiveResult->Write(), "123");

    std::list<std::string> negativeList = Data::CreateList("-123");
    pExp negativeResult = reader.Read(negativeList);
    EXPECT_EQ(negativeResult->WhoAmI(), "ValExp");
    EXPECT_EQ(negativeResult->Write(), "-123");
  }

  TEST_F(ReaderTest, ShouldReadBoolean)
  {
    std::list<std::string> trueList = Data::CreateList("#t");
    pExp trueResult = reader.Read(trueList);
    EXPECT_EQ(trueResult->WhoAmI(), "BoolExp");
    EXPECT_EQ(trueResult->Write(), "#t");

    std::list<std::string> falseList = Data::CreateList("#f");
    pExp falseResult = reader.Read(falseList);
    EXPECT_EQ(falseResult->WhoAmI(), "BoolExp");
    EXPECT_EQ(falseResult->Write(), "#f");
  }

  TEST_F(ReaderTest, ShouldReadSymbols) // TODO: check for other allowed symbol formats
  {
    std::list<std::string> symbolList = Data::CreateList("foobar");
    pExp result = reader.Read(symbolList);
    EXPECT_EQ(result->WhoAmI(), "SymbolExp");
    EXPECT_EQ(result->Write(), "foobar");
  }

  TEST_F(ReaderTest, ShouldReadEmptyList)
  {
    std::list<std::string> emptyList = Data::CreateList("()");
    pExp result = reader.Read(emptyList);
    EXPECT_EQ(result->WhoAmI(), "EmptyListExp");
    EXPECT_EQ(result->Write(), "");
  }

  TEST_F(ReaderTest, ShouldReadList)
  {
    std::list<std::string> simpleList = Data::CreateList("( 1 2 )");
    pExp simpleResult = reader.Read(simpleList);
    EXPECT_EQ(simpleResult->WhoAmI(), "PairExp");
    EXPECT_EQ(simpleResult->Write(), "1 2");

    std::list<std::string> nestedList = Data::CreateList("( 1 ( 2 3 ) )");
    pExp nestedResult = reader.Read(nestedList);
    EXPECT_EQ(nestedResult->WhoAmI(), "PairExp");
    EXPECT_EQ(nestedResult->Write(), "1 2 3");

    std::list<std::string> variadicList = Data::CreateList("(1 2 3 4 5)");
    pExp variadicResult = reader.Read(variadicList);
    EXPECT_EQ(variadicResult->WhoAmI(), "PairExp");
    EXPECT_EQ(variadicResult->Write(), "1 2 3 4 5");
  }

  TEST_F(ReaderTest, ShouldReadListWithEmptyListInside)
  {
    std::list<std::string> nullList = Data::CreateList("(null? ())");
    pExp checkResult = reader.Read(nullList);
    EXPECT_EQ(checkResult->WhoAmI(), "PairExp");
    EXPECT_EQ(checkResult->Write(), "null?");

    pExp lhs = car(checkResult);
    EXPECT_EQ(lhs->WhoAmI(), "SymbolExp");
    EXPECT_EQ(lhs->Write(), "null?");

    pExp rhs = cdr(checkResult);
    EXPECT_EQ(rhs->WhoAmI(), "EmptyListExp");
    EXPECT_EQ(rhs->Write(), "");
  }

  TEST_F(ReaderTest, ShouldReadQuotedSymbol)
  {
    std::list<std::string> quotedSymbolList = Data::CreateList("(quote symbol)");
    pExp result = reader.Read(quotedSymbolList);
    EXPECT_EQ(result->WhoAmI(), "PairExp");
    EXPECT_EQ(result->Write(), "quote symbol");
  }

  TEST_F(ReaderTest, ShouldReadQuotedList)
  {
    std::list<std::string> quotedList = Data::CreateList("(quote (1 2 3))");
    pExp result = reader.Read(quotedList);
    EXPECT_EQ(result->WhoAmI(), "PairExp");
    EXPECT_EQ(result->Write(), "quote 1 2 3");
  }

  TEST_F(ReaderTest, ShouldReadSingleQuotedInteger)
  {
    std::list<std::string> singleQuotedIntList = Data::CreateList("'42");
    pExp result = reader.Read(singleQuotedIntList);
    EXPECT_EQ(result->WhoAmI(), "PairExp");
    EXPECT_EQ(result->Write(), "quote 42");
  }

  TEST_F(ReaderTest, ShouldReadVariadicListWithSingleQuotes)
  {
    std::list<std::string> singleQuotedIntList = Data::CreateList("(if #f 'a 'b)");
    pExp result = reader.Read(singleQuotedIntList);
    EXPECT_EQ(result->WhoAmI(), "PairExp");
    EXPECT_EQ(result->Write(), "if #f quote a quote b");
  }

  TEST_F(ReaderTest, ShouldReadAddition)
  {
    std::list<std::string> additionList = Data::CreateList("(+ 1 2)");
    pExp additionResult = reader.Read(additionList);
    EXPECT_EQ(additionResult->WhoAmI(), "PairExp");
    EXPECT_EQ(additionResult->Write(), "+ 1 2");
  }
}

