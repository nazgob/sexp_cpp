#ifndef SET_H
#define SET_H

#include "Utils.hpp"
#include "Context.hpp"
#include "Procedure.hpp"
#include "SymbolExp.hpp"

namespace sexp_cpp
{
  
  class Set : public Procedure
  {
    public:
      virtual ~Set() {}
      static pProc Create() {return pProc(new Set());}

      virtual pExp Apply(pExp list, Context& context) const
      {
        context.Set(car(list)->Write(), cadr(list));
        return SymbolExp::Create("ok");
      }
  };
  
} // sexp_cpp

#endif // SET_H

