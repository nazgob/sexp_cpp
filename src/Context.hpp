#ifndef CONTEXT_H
#define CONTEXT_H

#include "Utils.hpp"

#include <map>

namespace sexp_cpp
{

  class Context
  {
    public:
      void Define(pSymbol symbol, pExp exp);
      void Define(const std::string& symbolName, pExp exp);

      void Set(pSymbol symbol, pExp exp);
      void Set(const std::string& symbolName, pExp exp);

      pExp Lookup(pSymbol symbol) const;
      pExp Lookup(const std::string& symbolName) const;

      void DefineFunc(const std::string& funcName, pFunc func);
      pFunc LookupFunc(const std::string& funcName) const;

    protected:
      typedef std::map<std::string, pExp> ContextValType;
      ContextValType mContextValMap;
      
      typedef std::map<std::string, pFunc> ContextFuncType;
      ContextFuncType mContextFuncMap;
  };

} // sexp_cpp

#endif // CONTEXT_H

