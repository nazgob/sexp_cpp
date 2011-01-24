#ifndef NULL_H
#define NULL_H

#include "Utils.hpp"
#include "Context.hpp"
#include "Procedure.hpp"
#include "BoolExp.hpp"

namespace sexp_cpp
{
  
  class Null : public Procedure
  {
    public:
      virtual ~Null() {}
      static pProc Create() {return pProc(new Null());}

      virtual pExp Apply(pExp list, Context&) const
      {
        if(list->WhoAmI() == "EmptyListExp")
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

#endif // NULL_H

