#include "VarExp.hpp"
#include "Context.hpp"
#include "ValueExp.hpp"

namespace sexp_cpp
{

  pExp VarExp::Evaluate(Context& context) const
  {
    return pExp(new ValueExp(context.Lookup(getVarName()))); // TODO: Context should use proper type!
  }

} // sexp_cpp

