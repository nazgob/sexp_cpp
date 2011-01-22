#include <gtest/gtest.h>

#include "DataFactory.hpp"
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
    std::string values = "(1 2 3 4 5)";
    std::list<std::string> valuesList = DataFactory::GetList(values);
    
    Reader reader;
    pExp valuesResult = reader.Read(valuesList);

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

