#include <gtest/gtest.h>
#include "../src/Context.hpp"
#include "../src/SymbolExp.hpp"
#include "../src/BoolExp.hpp"
#include "../src/ValExp.hpp"
#include "../src/NullExp.hpp"

using namespace sexp_cpp;

#include <stdexcept>

namespace
{
  TEST(ContextTest, DefineAndLookup)
  {
    Context context;
    pSymbol statusSymbol(new SymbolExp("status"));
    pExp statusVal(new BoolExp(true));
    
    context.Define(statusSymbol, statusVal);

    pExp tmp = context.Lookup("status")->Evaluate(context);
    EXPECT_EQ("#t", tmp->Write());
    EXPECT_EQ("BoolExp", tmp->WhoAmI());
  }

  TEST(ContextTest, DoubleDefineIsOK)
  {
    Context context;
    pSymbol symbol(new SymbolExp("foo"));
    
    pExp foo1(new ValExp(42));
    context.Define(symbol, foo1);
    pExp tmp1 = context.Lookup("foo")->Evaluate(context);
    EXPECT_EQ("42", tmp1->Write());
    EXPECT_EQ("ValExp", tmp1->WhoAmI());
    
    pExp foo2(new ValExp(123));
    context.Define(symbol, foo2);
    pExp tmp2 = context.Lookup(symbol)->Evaluate(context);
    EXPECT_EQ("123", tmp2->Write());
    EXPECT_EQ("ValExp", tmp2->WhoAmI());
  }

  TEST(ContextTest, SetPositive)
  {
    Context context;
    pSymbol symbol(new SymbolExp("foo"));
    
    pExp foo1(new ValExp(42));
    context.Define(symbol, foo1);
    pExp tmp1 = context.Lookup(symbol)->Evaluate(context);
    EXPECT_EQ("42", tmp1->Write());
    EXPECT_EQ("ValExp", tmp1->WhoAmI());
    
    pExp foo2(new ValExp(123));
    context.Set(symbol, foo2);
    pExp tmp2 = context.Lookup(symbol)->Evaluate(context);
    EXPECT_EQ("123", tmp2->Write());
    EXPECT_EQ("ValExp", tmp2->WhoAmI());
  }

  TEST(ContextTest, SetNegative)
  {
    Context context;
    
    pSymbol symbol(new SymbolExp("foo"));
    pExp null(new NullExp());

    EXPECT_THROW(context.Set(symbol, null), std::logic_error);
  }

  TEST(ContextTest, LookupOnEmpty)
  {
    Context context;
    EXPECT_THROW(context.Lookup("foobar"), std::runtime_error);
  }

} 

