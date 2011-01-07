#ifndef CONTEXT_H
#define CONTEXT_H

#include "Utils.hpp"

#include <map>

namespace sexp_cpp
{

  class Context
  {
    public:
      Context();
      ~Context();
      void Assign(pVar exp, int value);
      int Lookup(const std::string& varName) const;

      void Assign(pOp op);
      //pOp GetOp() const {return mOp;}

    protected:
      typedef std::map<std::string, int> ContextType;
      ContextType mContextMap;
      //pOp mOp;
  };

} // sexp_cpp

#endif // CONTEXT_H

