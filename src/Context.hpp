#ifndef CONTEXT_H
#define CONTEXT_H

#include "Utils.hpp"
#include "SymbolExp.hpp"

#include <map>

namespace sexp_cpp
{

  class Context
  {
    public:
      void Define(const std::string& varName, pExp exp);
      void Set(const std::string& varName, pExp exp);
      pExp Lookup(const std::string& varName) const;

    protected:
      typedef std::map<std::string, pExp> ContextType;
      ContextType mContextMap;
  };

} // sexp_cpp

#endif // CONTEXT_H

