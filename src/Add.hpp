#ifndef ADD_H
#define ADD_H

#include "Utils.hpp"
#include "Procedure.hpp"
#include "ValExp.hpp"
#include "EmptyListExp.hpp"

#include <boost/lexical_cast.hpp>

namespace sexp_cpp
{

  class Context;

  class Add : public Procedure
  {
    public:
      virtual ~Add() {}
      static pProc Create() {return pProc(new Add());}

      virtual pExp Apply(pExp list, Context& context) const
      {
        int result = 0;
        if(list->WhoAmI() == "EmptyListExp")
        {
          return EmptyListExp::Create();
        }
        while(list->WhoAmI() != "EmptyListExp")
        {
          result += boost::lexical_cast<int>(car(list)->Evaluate(context)->Write());
          list = cdr(list);
        }
        return ValExp::Create(result);
      }
  };

} // sexp_cpp

#endif // ADD_H

