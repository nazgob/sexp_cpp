#include "Context.hpp"
#include "VarExp.hpp"
#include "Operator.hpp"
#include "Utils.hpp"

#include <stdexcept>
#include <cassert>

namespace sexp_cpp
{

  Context::Context()
  {
    mOp.reset(new NullOperator());
  }

  Context::~Context() {}

  int Context::Lookup(const std::string& varName) const
  {
    ContextType::const_iterator it = mContextMap.find(varName);

    if(it != mContextMap.end())
    {
      return it->second;
    }
    else
    {
      throw std::runtime_error("context error / undefined variable: " + varName);
    }
  }

  void Context::Assign(pOp op)
  {
    mOp = op;
  }

  void Context::Assign(pVar exp, int value)
  {
    mContextMap[exp->getVarName()] = value;
  }

} // sexp_cpp

