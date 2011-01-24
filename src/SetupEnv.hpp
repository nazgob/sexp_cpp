#ifndef SETUPENV_HPP
#define SETUPENV_HPP

#include "Func.hpp"
#include "Add.hpp"
#include "Quote.hpp"
#include "Define.hpp"
#include "Set.hpp"
#include "If.hpp"
#include "Null.hpp"
#include "Boolean.hpp"

namespace sexp_cpp
{
  void SetupEnv(Context& context)
  {
    context.DefineFunc("+",        Func::Create(Add::Create()));
    context.DefineFunc("quote",    Func::Create(Quote::Create()));
    context.DefineFunc("define",   Func::Create(Define::Create()));
    context.DefineFunc("set!",     Func::Create(Set::Create()));
    context.DefineFunc("if",       Func::Create(If::Create()));
    context.DefineFunc("null?",    Func::Create(Null::Create()));
    context.DefineFunc("boolean?", Func::Create(Boolean::Create()));
  }

} //sexp_cpp

#endif // SETUPENV_HPP

