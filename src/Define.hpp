#ifndef DEFINE_H
#define DEFINE_H

#include "Utils.hpp"
#include "Context.hpp"
#include "Procedure.hpp"
#include "SymbolExp.hpp"

namespace sexp_cpp
{
  
  class Define : public Procedure
  {
    public:
      virtual ~Define() {}
      static pProc Create() {return pProc(new Define());}

      virtual pExp Apply(pExp list, Context& context) const
      {
        context.Define(car(list)->Write(), cadr(list));
        return SymbolExp::Create("ok");
      }
  };
  
} // sexp_cpp

#endif // DEFINE_H

