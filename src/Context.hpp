#ifndef CONTEXT_H
#define CONTEXT_H

#include "Utils.hpp"

#include <map>

namespace sexp_cpp
{

  class Context
  {
    public:
      void Define(const std::string& varName, int value);
      void Set(const std::string& varName, int value);
      int Lookup(const std::string& varName) const;

    protected:
      //typedef std::map<std::string, pExp> TestContextType; //TODO !!!
      typedef std::map<std::string, int> ContextType;
      ContextType mContextMap;
  };

} // sexp_cpp

#endif // CONTEXT_H

