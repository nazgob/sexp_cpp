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

    protected:
      typedef std::map<std::string, pExp> ContextType;
      ContextType mContextMap;
  };

} // sexp_cpp

#endif // CONTEXT_H

