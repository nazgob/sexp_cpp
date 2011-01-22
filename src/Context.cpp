#include "Context.hpp"
#include "Utils.hpp"
#include "SymbolExp.hpp"

#include <stdexcept>
#include <cassert>

namespace sexp_cpp
{

  void Context::Define(pSymbol symbol, pExp exp)
  {
    Define(symbol->GetName(), exp);
  }

  void Context::Define(const std::string& symbolName, pExp exp)
  {
    mContextValMap[symbolName] = exp;
  }

  void Context::Set(pSymbol symbol, pExp exp)
  {
    Set(symbol->GetName(), exp);
  }

  void Context::Set(const std::string& symbolName, pExp exp)
  {
    if(mContextValMap.find(symbolName) != mContextValMap.end())
    {
      mContextValMap[symbolName] = exp;
    }
    else
    {
      throw std::logic_error("context error / undefined variable set: " + symbolName);
    }
  }

  pExp Context::Lookup(pSymbol symbol) const
  {
    return Lookup(symbol->GetName());
  }

  pExp Context::Lookup(const std::string& symbolName) const
  {
    ContextValType::const_iterator it = mContextValMap.find(symbolName);

    if(it != mContextValMap.end())
    {
      return it->second;
    }
    else
    {
      throw std::runtime_error("context error / undefined variable lookup: " + symbolName);
    }
  }

  void Context::DefineFunc(const std::string& funcName, pFunc func)
  {
    mContextFuncMap[funcName] = func;
  }

  pFunc Context::LookupFunc(const std::string& funcName) const
  {
    ContextFuncType::const_iterator it = mContextFuncMap.find(funcName);

    if(it != mContextFuncMap.end())
    {
      return it->second;
    }
    else
    {
      throw std::runtime_error("context error / undefined function lookup: " + funcName);
    }
  }

} // sexp_cpp

