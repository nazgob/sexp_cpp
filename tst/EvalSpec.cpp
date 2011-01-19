#include <gtest/gtest.h>

#include "../src/Repl.hpp"
#include "../src/Exp.hpp"
#include "../src/Context.hpp"
#include "../src/SymbolExp.hpp"
#include "../src/ValExp.hpp"

#include <sstream>
#include <string>

using namespace sexp_cpp;

namespace
{
  TEST(EvalSpec, PositiveIntegerExp)
  {
    std::stringstream code("123");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "ValExp");
    EXPECT_EQ("123", print(exp));
  }
  
  TEST(EvalSpec, NegativeIntegerExp)
  {
    std::stringstream code("-456");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "ValExp");
    EXPECT_EQ("-456", print(exp));
  }
  
  TEST(EvalSpec, TrueBooleanExp)
  {
    std::stringstream code("#t");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "BoolExp");
    EXPECT_EQ("#t", print(exp));
  }

  TEST(EvalSpec, FalseBooleanExp)
  {
    std::stringstream code("#f");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "BoolExp");
    EXPECT_EQ("#f", print(exp));
  }
  
  TEST(EvalSpec, SymbolExp)
  {
    std::stringstream code("foobar");

    context.Define(SymbolExp::Create("foobar"), ValExp::Create(42));

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "ValExp");
    EXPECT_EQ("42", print(exp));
  }

  TEST(EvalSpec, EmptyListExp)
  {
    std::stringstream code("()");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "EmptyListExp");
    EXPECT_EQ("", print(exp));
  }

  TEST(EvalSpec, PairExp)
  {
    std::stringstream code("(1 2)");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "PairExp");
    EXPECT_EQ("(1 2)", print(exp));
  }
  
  TEST(EvalSpec, PairExpWithExtraSpaces)
  {
    std::stringstream code(" ( 1  2 ) ");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "PairExp");
    EXPECT_EQ("(1 2)", print(exp));
  }
  
  TEST(EvalSpec, NestedPairExp)
  {
    std::stringstream code("(1 2 3 4 5)");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "PairExp");
    EXPECT_EQ("(1 2 3 4 5)", print(exp));
  }

  TEST(EvalSpec, QuoteList)
  {
    std::stringstream code("(quote (1 2 3))");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "PairExp");
    EXPECT_EQ("(1 2 3)", print(exp));
  }
  
  TEST(EvalSpec, SingleQuoteList)
  {
    std::stringstream code("'(1 2 3)");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "PairExp");
    EXPECT_EQ("(1 2 3)", print(exp));
  }

  TEST(EvalSpec, QuoteInteger)
  {
    std::stringstream code("(quote 1)");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "ValExp");
    EXPECT_EQ("1", print(exp));
  }

  TEST(EvalSpec, SingleQuoteInteger)
  {
    std::stringstream code("'42");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "ValExp");
    EXPECT_EQ("42", print(exp));
  }

  TEST(EvalSpec, DefineTest)
  {
    std::stringstream code("(define foo 55)");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "SymbolExp");
    EXPECT_EQ("ok", print(exp));

    pExp tmp = context.Lookup("foo")->Evaluate(context);
    EXPECT_EQ("55", tmp->Write());
    EXPECT_EQ("ValExp", tmp->WhoAmI());
  }
  
  TEST(EvalSpec, SetTest)
  {
    std::stringstream code("(set! bar 77)");

    context.Define(SymbolExp::Create("bar"), ValExp::Create(0));

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "SymbolExp");
    EXPECT_EQ("ok", print(exp));

    pExp tmp = context.Lookup("bar")->Evaluate(context);
    EXPECT_EQ("77", tmp->Write());
    EXPECT_EQ("ValExp", tmp->WhoAmI());
  }

  TEST(EvalSpec, IfTrueTest)
  {
    std::stringstream code("(if #t 1 2)");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "ValExp");
    EXPECT_EQ("1", print(exp));
  }
  
  TEST(EvalSpec, IfFalseTest)
  {
    std::stringstream code("(if #f 1 2)");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "ValExp");
    EXPECT_EQ("2", print(exp));
  }
  
  TEST(EvalSpec, IfTrueWithQuote)
  {
    std::stringstream code("(if #t (quote 1) 42))");

    pExp exp = eval(read(code));
    exp = eval(exp); // TODO: move to Evaluate!
    EXPECT_EQ(exp->WhoAmI(), "ValExp");
    EXPECT_EQ("1", print(exp));
  }
  
  TEST(EvalSpec, IfFalseWithQuote)
  {
    std::stringstream code("(if #f 1 (quote 42))");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "ValExp");
    EXPECT_EQ("42", print(exp));
  }
  
  TEST(EvalSpec, IfWithDoubleQuotes)
  {
    std::stringstream code("(if #f (quote 1) (quote 2))");

    pExp exp = read(code);
    exp = eval(exp);
    EXPECT_EQ(exp->WhoAmI(), "ValExp");
    EXPECT_EQ("2", print(exp));
  }
    
  //TODO: fix single quoting in complex expressions std::stringstream code("(if #f 'a 'b)");
  
}

