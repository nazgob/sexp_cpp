#include <gtest/gtest.h>

#include "../src/Repl.hpp"
#include "../src/Exp.hpp"

#include <sstream>
#include <string>

using namespace sexp_cpp;

namespace
{

  TEST(EvalSpec, lol)
  {
    std::stringstream code("( quote a )");
    pExp exp = eval(read(code));

    EXPECT_EQ(exp->WhoAmI(), "PairExp");
    EXPECT_EQ(exp->Write(), "( quote ( a () ) )");
  }

}

