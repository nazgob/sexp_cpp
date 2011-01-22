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
 
  //TODO: make it generic Func method cusomizable by Evaluate strategy
  class AddFunc : public Exp
  {
    public:
      AddFunc() : mList(EmptyListExp::Create()) {}
      AddFunc(pExp list) : mList(list) {} //TODO: consider adding "+" as field
      virtual ~AddFunc() {}
      
      static pFunc Create() { return pFunc(new AddFunc());}
      static pExp Create(pExp list) { return pExp(new AddFunc(list));}

      virtual pExp Evaluate(Context&) const
      {
        pExp list = mList;
        int result = 0;
        if(list->WhoAmI() == "EmptyListExp")
        {
          return Create();
        }

        while(list->WhoAmI() != "EmptyListExp")
        {
          result += boost::lexical_cast<int>(car(list)->Write());
          list = cdr(list);
        }
        return ValExp::Create(result);
      }

      virtual std::string WhoAmI() const {return "AddFunc";}
      
      virtual std::string Write() const
      {
        return "#<procedure>";
      }

      void SetList(pExp list) {mList = list;}
      
    protected:
      pExp mList;
  };

} // sexp_cpp

#endif // ADD_FUNC_H

