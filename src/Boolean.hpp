#ifndef BOOLEAN_H
#define BOOLEAN_H

#include "Utils.hpp"
#include "Context.hpp"
#include "Procedure.hpp"
#include "BoolExp.hpp"

namespace sexp_cpp
{

  class Boolean : public Procedure
  {
    public:
      virtual ~Boolean() {}
      static pProc Create() {return pProc(new Boolean());}

      virtual pExp Apply(pExp list, Context&) const
      {
        if(list->Write() == "#t" || list->Write() == "#f")
        {
          return BoolExp::Create(true);
        }
        else
        {
          return BoolExp::Create(false);
        }
      }
  };

} // sexp_cpp

#endif // BOOLEAN_H

