#include <gtest/gtest.h>

#include "Data.hpp"
#include "../src/Reader.hpp"
#include "../src/Exp.hpp"
#include "../src/Context.hpp"
#include "../src/Func.hpp"
#include "../src/Add.hpp"

#include <string>

using namespace sexp_cpp;

namespace
{

  class AddTest : public ::testing::Test
  {
    void SetUp()
    {
     func = Func::Create(Add::Create());
    }
    protected:
      Context context;
      pFunc func;
  };

  TEST_F(AddTest, JustSumItUp)
  {
    pExp valuesResult = Data::CreateExp("(1 2 3 4 5)");

    func->SetList(valuesResult);

    pExp result = func->Evaluate(context);
    EXPECT_EQ(result->WhoAmI(), "ValExp");
    EXPECT_EQ(result->Write(), "15");
  }

  TEST_F(AddTest, EvalToEmptyListWhenNoListProvided)
  {
    pExp result = func->Evaluate(context);
    EXPECT_EQ(result->WhoAmI(), "EmptyListExp");
    EXPECT_EQ(result->Write(), "");
  }
}

