#include <gtest/gtest.h>
#include "../src/VarExp.h"
#include "../src/Operator.h"
#include "../src/Context.h"

using namespace sexp_cpp;

#include <stdexcept>

namespace
{
  TEST(PlayHard, dummy)
  {
    class Foo
    {
      public:
        Foo(pExp bar)
        {
          mBar = bar;
        }
      private:
        pExp mBar;
    };

    pExp bar(new VarExp("bar"));
    Foo foo(bar);
  }

  TEST(ContextTest, LookupPositive)
  {
    Context context;
    pVar varFoo(new VarExp("foo"));
    pVar varBar(new VarExp("bar"));

    context.Assign(varFoo, 1);
    context.Assign(varBar, 2);

    EXPECT_EQ(1, context.Lookup("foo"));
    EXPECT_EQ(2, context.Lookup("bar"));
  }

  TEST(ContextTest, LookupOnEmpty)
  {
    Context context;
    EXPECT_THROW(context.Lookup("foobar"), std::runtime_error);
  }

  TEST(ContextTest, GetDefaultOperator)
  {
    Context context;
    pOp op(context.GetOp());
    EXPECT_EQ("NullOperator", op->WhoAmI());
  }
  
  TEST(ContextTest, SetAndGetOperator)
  {
    Context context;
    pOp op(new AddOperator());
    context.Assign(op);
    EXPECT_EQ("AddOperator", op->WhoAmI());
  }
} 

