#include <gtest/gtest.h>

#include "../src/Repl.hpp"
#include "../src/Exp.hpp"

#include <sstream>
#include <string>

using namespace sexp_cpp;

namespace
{
  TEST(EvalSpec, PositiveIntegerExp)
  {
    std::stringstream code("123");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "ValueExp");
    EXPECT_EQ("123", print(exp));
  }
  
  TEST(EvalSpec, NegativeIntegerExp)
  {
    std::stringstream code("-456");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "ValueExp");
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

  TEST(EvalSpec, EmptyListExp)
  {
    std::stringstream code("()");

    pExp exp = eval(read(code));
    EXPECT_EQ(exp->WhoAmI(), "EmptyListExp");
    EXPECT_EQ("", print(exp));
  }

  TEST(EvalSpec, PairExp)
  {
    std::stringstream code("( 1 2 )");

    pExp exp = read(code);
    EXPECT_EQ(exp->WhoAmI(), "PairExp");

    exp = eval(exp);

    EXPECT_EQ(exp->WhoAmI(), "PairExp");
    EXPECT_EQ("(1 2)", print(exp));
  }
  
  TEST(EvalSpec, NestedPairExp)
  {
    std::stringstream code("( 1 2 3 4 5 )");
    pExp exp = eval(read(code));

    EXPECT_EQ(exp->WhoAmI(), "PairExp");
    EXPECT_EQ("(1 2 3 4 5)", print(exp));
  }

  //TEST(EvalSpec, Quote)
  //{
    //std::stringstream code("( quote a )");
    //pExp exp = eval(read(code));

    //EXPECT_EQ(exp->WhoAmI(), "PairExp");
    //EXPECT_EQ("a", print(exp));
  //}

}

