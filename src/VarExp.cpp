#include "VarExp.h"
#include "Context.h"

namespace sexp_cpp
{

  int VarExp::Evaluate(Context& context) const
  {
    return context.Lookup(getVarName());
  }

} // sexp_cpp

