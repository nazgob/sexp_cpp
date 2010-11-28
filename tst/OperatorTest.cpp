#include <gtest/gtest.h>

#include "../src/VarExp.hpp"
#include "../src/Operator.hpp"
#include "../src/Context.hpp"

using namespace sexp_cpp;

namespace
{

  TEST(OperatorTest, OperatorInit)
  {
    Context context;

    pVar varFoo(new VarExp("foo"));
    pVar varBar(new VarExp("bar"));

    context.Assign(varFoo, 3);
    context.Assign(varBar, 2);

    pOp addOp(new AddOperator());
    pOp subOp(new SubOperator());

    EXPECT_EQ(5, addOp->Evaluate(varFoo, varBar, context));
    EXPECT_EQ(1, subOp->Evaluate(varFoo, varBar, context));
  }

} 

