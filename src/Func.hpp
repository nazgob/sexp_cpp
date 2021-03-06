#ifndef ADD_FUNC_H
#define ADD_FUNC_H

#include "Utils.hpp"
#include "Procedure.hpp"
#include "ValExp.hpp"
#include "EmptyListExp.hpp"

#include <string>
#include <stdexcept>
#include <boost/lexical_cast.hpp>

namespace sexp_cpp
{
  class Context;

  class Func : public Exp
  {
    public:
      Func(pProc add) : mProc(add), mList(EmptyListExp::Create()) {}
      virtual ~Func() {}
      
      static pFunc Create(pProc proc) {return pFunc(new Func(proc));}

      virtual pExp Evaluate(Context& context) const
      {
        return mProc->Apply(mList, context);
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

