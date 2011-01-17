#include "Context.hpp"
#include "Utils.hpp"

#include <stdexcept>
#include <cassert>

namespace sexp_cpp
{

  void Context::Define(const std::string& varName, pExp exp)
  {
    mContextMap[varName] = exp;
  }

  void Context::Set(const std::string& varName, pExp exp)
  {
    if(mContextMap.find(varName) != mContextMap.end())
    {
      mContextMap[varName] = exp;
    }
    else
    {
      throw std::logic_error("context error / undefined variable set: " + varName);
    }
  }

  pExp Context::Lookup(const std::string& varName) const
  {
    ContextType::const_iterator it = mContextMap.find(varName); // TODO: fix...

    if(it != mContextMap.end())
    {
      return it->second;
    }
    else
    {
      throw std::runtime_error("context error / undefined variable lookup: " + varName);
    }
  }

} // sexp_cpp

