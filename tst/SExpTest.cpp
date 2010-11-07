#include <gtest/gtest.h>
#include "../src/SExp.h"
#include "../src/VarExp.h"
#include "../src/ValueExp.h"
#include "../src/Operator.h"
#include "../src/Context.h"
#include "../src/Utils.h"

using namespace sexp_cpp;

#include <stdexcept>

namespace
{

	class SExpTest : public ::testing::Test
	{
		protected:
			virtual void SetUp()
			{
				a.reset(new VarExp("a"));
				b.reset(new VarExp("b"));
				c.reset(new VarExp("c"));
				d.reset(new VarExp("d"));

				context.Assign(a, 2);
				context.Assign(b, 3);
				context.Assign(c, 4);
				context.Assign(d, 5);
			}

			pVar a;
			pVar b;
			pVar c;
			pVar d;

			Context context;
	};

	TEST_F(SExpTest, NoOperatorDefined)
	{
		// (4 5) = 9
		pOp op(new NullOperator());
		pSExp sExp(new SExp(c, d, op));
		EXPECT_THROW(sExp->Evaluate(context), std::logic_error);
	}
	
	TEST_F(SExpTest, SimplestCorrectSExp)
	{
		// (+ 4 5) = 9
		pOp op(new AddOperator());
		pSExp sExp(new SExp(c, d, op));
		EXPECT_EQ(9, sExp->Evaluate(context));
	}

	TEST_F(SExpTest, NestedSExp)
	{
		// x = (+ 4 5) = 9
		// y = (+ 3 x) = 12
		// z = (+ 2 y) = 14
		// (+ 2 (+ 3 (+ 4 5))) = 14

		pOp op(new AddOperator());

		pSExp x(new SExp(c, d, op));
		EXPECT_EQ(9, x->Evaluate(context));

		pSExp y(new SExp(b, x, op));
		EXPECT_EQ(12, y->Evaluate(context));

		pSExp z(new SExp(a, y, op));
		EXPECT_EQ(14, z->Evaluate(context));
	}

	TEST_F(SExpTest, SExpWithOperator)
	{
		// (+ 2 3) = 5
		pOp addOp(new AddOperator());
		pSExp addOpWithValue(new SExp(a, b, addOp));
		EXPECT_EQ(5, addOpWithValue->Evaluate(context));

		// (- 2 3) = -1
		pOp subOp(new SubOperator());
		pSExp subOpWithValue(new SExp(a, b, subOp));
		EXPECT_EQ(-1, subOpWithValue->Evaluate(context));
	}

	TEST_F(SExpTest, TwoOperatorsInSExp)
	{
		// (-, ( (+, (2 3)), 4)) = (-, (5, 4)) = 1

		pOp nullOp(new NullOperator());
		pOp addOp(new AddOperator());
		pOp subOp(new SubOperator());

		// (2 3)
		pSExp first(new SExp(a, b, nullOp));
		EXPECT_THROW(first->Evaluate(context), std::logic_error);

		// (+ 2 3) = 5
		pSExp second(new SExp(a, b, addOp));
		EXPECT_EQ(5, second->Evaluate(context));

		// (- 4 (+ 2 3)) = -1
		pSExp third(new SExp(c, second, subOp));
		EXPECT_EQ(-1, third->Evaluate(context));
	}

	TEST_F(SExpTest, OneOperatorManyValues)
	{
		// (+, (5, (4, (3, 2,))))
		// (+ 5 4 3 2) = 14
		pOp addOp(new AddOperator());

		pExp one(new SExp(a, b, addOp));
		pExp two(new SExp(c, one, addOp));
		pExp three(new SExp(d, two, addOp));
		EXPECT_EQ(14, three->Evaluate(context));
	}

	TEST(SExpWithValuesTest, SimplestCorrectSExpNoVariables)
	{
		// (+ 4 5) = 9
    Context context;

		pOp op(new AddOperator());
    pVal a(new ValueExp(4)); 
    pVal b(new ValueExp(5)); 
		pSExp sExp(new SExp(a, b, op));
		EXPECT_EQ(9, sExp->Evaluate(context));
	}

} 

