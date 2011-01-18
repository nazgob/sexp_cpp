#ifndef EMPTY_LIST_EXP_H
#define EMPTY_LIST_EXP_H 

#include "Exp.hpp"
#include "Utils.hpp"

#include <string>

namespace sexp_cpp
{
  class Context;

  class EmptyListExp : public Exp 
  {
    public:
      EmptyListExp() {}
      virtual ~EmptyListExp() {}
      
      static pExp Create() { return pExp(new EmptyListExp());}

      virtual pExp Evaluate(Context&) const {return Create();}

      virtual std::string WhoAmI() const {return "EmptyListExp";}

      virtual std::string Write() const
      {
        return "";
      }
  };

} // sexp_cpp

#endif // EMPTY_LIST_EXP_H

