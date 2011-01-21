#include <gtest/gtest.h>

#include "DataFactory.hpp"
#include "../src/Reader.hpp"
#include "../src/Exp.hpp"
#include "../src/Context.hpp"
#include "../src/AddFunc.hpp"

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
    AddFunc addFunc(valuesResult);

    pExp result = addFunc.Evaluate(context);
    EXPECT_EQ(result->WhoAmI(), "ValExp");
    EXPECT_EQ(result->Write(), "15");
  }
  
  TEST(AddFunc, EvalToItSelfWhenEmptyListProvided)
  {
    Context context;
    AddFunc addFunc(EmptyListExp::Create());

    pExp result = addFunc.Evaluate(context);
    EXPECT_EQ(result->WhoAmI(), "AddFunc");
    EXPECT_EQ(result->Write(), "#<procedure>");
  }
}

