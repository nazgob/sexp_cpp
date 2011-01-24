#ifndef IF_H
#define IF_H

#include "Utils.hpp"
#include "Context.hpp"
#include "Procedure.hpp"
#include "BoolExp.hpp"

namespace sexp_cpp
{

  class If : public Procedure
  {
    public:
      virtual ~If() {}
      static pProc Create() {return pProc(new If());}

      virtual pExp Apply(pExp list, Context& context) const
      {
        if(car(list)->Write() != "#f")
        {
          //TODO: this eval call is instead of proper tail recursion!
          return cadr(list)->Evaluate(context); 
        }
        else if(cadr(list)->Write() == "()")
        {
          return BoolExp::Create(false);
        }
        else
        {
          //TODO: this eval call is instead of proper tail recursion!
          return caddr(list)->Evaluate(context);
        }
      }
  };

} // sexp_cpp

#endif // IF_H

