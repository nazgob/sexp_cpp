#ifndef ADD_FUNC_H
#define ADD_FUNC_H

#include "Exp.hpp"
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
  
  class AddFunc : public Exp 
  {
    public:
      AddFunc(pExp list) : mList(list) {}
      virtual ~AddFunc() {}
      
      static pExp Create(pExp list) { return pExp(new AddFunc(list));}

      virtual pExp Evaluate(Context&) const
      {
        pExp list = mList;
        int result = 0;
        if(list->WhoAmI() == "EmptyListExp")
        {
          return Create(AddFunc::Create(EmptyListExp::Create()));
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
      
      virtual pExp Car() const {throw std::logic_error("AddFunc::Car() called!");}
      virtual pExp Cdr() const {throw std::logic_error("AddFunc::Cdr() called!");}

    protected:
      pExp mList;
  };

} // sexp_cpp

#endif // ADD_FUNC_H

