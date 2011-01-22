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
  TEST(AddFunc, JustSumItUp)
  {
    pExp valuesResult = Data::CreateExp("(1 2 3 4 5)");

    Context context;
    pFunc func = Func::Create(Add::Create());
    func->SetList(valuesResult);

    pExp result = func->Evaluate(context);
    EXPECT_EQ(result->WhoAmI(), "ValExp");
    EXPECT_EQ(result->Write(), "15");
  }
  
  TEST(AddFunc, EvalToEmptyListWhenNoListProvided)
  {
    Context context;
    pFunc func = Func::Create(Add::Create());

    pExp result = func->Evaluate(context);
    EXPECT_EQ(result->WhoAmI(), "EmptyListExp");
    EXPECT_EQ(result->Write(), "");
  }
}

