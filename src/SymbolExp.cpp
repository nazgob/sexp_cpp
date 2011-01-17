#include "SymbolExp.hpp"
#include "Context.hpp"

namespace sexp_cpp
{

  pExp SymbolExp::Evaluate(Context& context) const
  {
    return context.Lookup(mSymbolName);
  }

} // sexp_cpp

