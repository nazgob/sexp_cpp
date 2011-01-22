#include <gtest/gtest.h>
#include "../src/Context.hpp"
#include "../src/Reader.hpp"
#include "../src/SymbolExp.hpp"
#include "../src/BoolExp.hpp"
#include "../src/ValExp.hpp"
#include "../src/NullExp.hpp"
#include "../src/Func.hpp"
#include "../src/Add.hpp"

#include "DataFactory.hpp"

using namespace sexp_cpp;

#include <stdexcept>

namespace
{
  TEST(ContextTest, DefineAndLookup)
  {
    Context context;
    context.Define(SymbolExp::Create("status"),
                   BoolExp::Create(true));

    pExp tmp = context.Lookup("status")->Evaluate(context);
    EXPECT_EQ("#t", tmp->Write());
    EXPECT_EQ("BoolExp", tmp->WhoAmI());
  }

  TEST(ContextTest, DoubleDefineIsOK)
  {
    Context context;
    pSymbol symbol = SymbolExp::Create("foo");
    
    context.Define(symbol, ValExp::Create(42));
    pExp tmp1 = context.Lookup("foo")->Evaluate(context);
    EXPECT_EQ("42", tmp1->Write());
    EXPECT_EQ("ValExp", tmp1->WhoAmI());
    
    context.Define(symbol, ValExp::Create(123));
    pExp tmp2 = context.Lookup(symbol)->Evaluate(context);
    EXPECT_EQ("123", tmp2->Write());
    EXPECT_EQ("ValExp", tmp2->WhoAmI());
  }

  TEST(ContextTest, SetPositive)
  {
    Context context;
    pSymbol symbol = SymbolExp::Create("foo");
    
    context.Define(symbol, ValExp::Create(42));
    pExp tmp1 = context.Lookup(symbol)->Evaluate(context);
    EXPECT_EQ("42", tmp1->Write());
    EXPECT_EQ("ValExp", tmp1->WhoAmI());
    
    context.Set(symbol, ValExp::Create(123));
    pExp tmp2 = context.Lookup(symbol)->Evaluate(context);
    EXPECT_EQ("123", tmp2->Write());
    EXPECT_EQ("ValExp", tmp2->WhoAmI());
  }

  TEST(ContextTest, SetNegative)
  {
    Context context;
    EXPECT_THROW(context.Set(SymbolExp::Create("foo"), NullExp::Create()), std::logic_error);
  }

  TEST(ContextTest, LookupOnEmpty)
  {
    Context context;
    EXPECT_THROW(context.Lookup("foobar"), std::runtime_error);
  }

  TEST(ContextTest, DefineAndLookupFunc)
  {
    Context context;
    context.DefineFunc("+", Func::Create(Add::Create())); //TODO: make a factory for common procedures!

    pFunc addition = context.LookupFunc("+");
    EXPECT_EQ("Func", addition->WhoAmI());
    EXPECT_EQ("#<procedure>", addition->Write());

    std::string values = "(1 2 3 4 5)";
    std::list<std::string> valuesList = DataFactory::GetList(values);
    
    Reader reader;
    pExp valuesResult = reader.Read(valuesList);

    addition->SetList(valuesResult);
    pExp result = addition->Evaluate(context);
    EXPECT_EQ("ValExp", result->WhoAmI());
    EXPECT_EQ("15", result->Write());
  }
} 

