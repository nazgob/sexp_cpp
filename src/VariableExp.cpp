#include "VarExp.h"
#include "Context.h"

namespace sexp_cpp
{

  int VarExp::Evaluate(Context& context) const
  {
    return context.Lookup(getVarName());
  }

  const std::string& VarExp::getVarName() const
  {
    return mVarName;
  }

} // sexp_cpp

