#include "Context.hpp"
#include "Utils.hpp"
#include "SymbolExp.hpp"

#include <stdexcept>
#include <cassert>

namespace sexp_cpp
{

  void Context::Define(pSymbol symbol, pExp exp)
  {
    mContextMap[symbol->GetName()] = exp;
  }

  void Context::Set(pSymbol symbol, pExp exp)
  {
    if(mContextMap.find(symbol->GetName()) != mContextMap.end())
    {
      mContextMap[symbol->GetName()] = exp;
    }
    else
    {
      throw std::logic_error("context error / undefined variable set: " + symbol->GetName());
    }
  }

  pExp Context::Lookup(pSymbol symbol) const
  {
    return Lookup(symbol->GetName());
  }

  pExp Context::Lookup(const std::string& symbolName) const
  {
    ContextType::const_iterator it = mContextMap.find(symbolName);

    if(it != mContextMap.end())
    {
      return it->second;
    }
    else
    {
      throw std::runtime_error("context error / undefined variable lookup: " + symbolName);
    }
  }

} // sexp_cpp

