#ifndef ADD_FUNC_H
#define ADD_FUNC_H

#include "Utils.hpp"
#include "ValExp.hpp"
#include "EmptyListExp.hpp"

#include <string>
#include <stdexcept>
#include <boost/lexical_cast.hpp>

namespace sexp_cpp
{
  class Context;
  class Exp;

  class Procedure
  {
    public:
      virtual pExp Apply(pExp list) const = 0;
  };

  class Add : public Procedure
  {
    public:
      virtual ~Add() {}
      static pProc Create() {return pProc(new Add());}

      virtual pExp Apply(pExp list) const
      {
        int result = 0;
        if(list->WhoAmI() == "EmptyListExp")
        {
          return EmptyListExp::Create();
        }
        while(list->WhoAmI() != "EmptyListExp")
        {
          result += boost::lexical_cast<int>(car(list)->Write());
          list = cdr(list);
        }
        return ValExp::Create(result);
      }
  };

  class Func : public Exp
  {
    public:
      Func(pProc add) : mProc(add), mList(EmptyListExp::Create()) {}
      virtual ~Func() {}
      
      static pFunc Create(pProc proc) {return pFunc(new Func(proc));}

      virtual pExp Evaluate(Context&) const
      {
        return mProc->Apply(mList);
      }

      virtual std::string WhoAmI() const {return "Func";}
      
      virtual std::string Write() const
      {
        return "#<procedure>";
      }

      void SetList(pExp list) {mList = list;}
      
    protected:
      pProc mProc;
      pExp mList;
  };

} // sexp_cpp

#endif // ADD_FUNC_H

