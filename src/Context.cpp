#include "Context.hpp"
#include "VarExp.hpp"
#include "Utils.hpp"

#include <stdexcept>
#include <cassert>

namespace sexp_cpp
{

  void Context::Define(const std::string& varName, int value)
  {
    mContextMap[varName] = value;
  }

  void Context::Set(const std::string& varName, int value)
  {
    if(mContextMap.find(varName) != mContextMap.end())
    {
      mContextMap[varName] = value;
    }
    else
    {
      throw std::logic_error("context error / undefined variable set: " + varName);
    }
  }

  int Context::Lookup(const std::string& varName) const
  {
    ContextType::const_iterator it = mContextMap.find(varName);

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

