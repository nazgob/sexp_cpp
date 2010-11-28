#include "VarExp.hpp"
#include "Context.hpp"

namespace sexp_cpp
{

  int VarExp::Evaluate(Context& context) const
  {
    return context.Lookup(getVarName());
  }

} // sexp_cpp

