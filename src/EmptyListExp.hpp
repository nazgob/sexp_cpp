#ifndef EMPTY_LIST_EXP_H
#define EMPTY_LIST_EXP_H 

#include "Exp.hpp"

#include <string>

namespace sexp_cpp
{
  class Context;

  class EmptyListExp : public Exp 
  {
    public:
      EmptyListExp() {}
      virtual ~EmptyListExp() {}

      virtual pExp Evaluate(Context&) const {return pExp(new EmptyListExp());}

      virtual std::string WhoAmI() const {return "EmptyListExp";}

      virtual std::string Write() const
      {
        return "";
      }
  };

} // sexp_cpp

#endif // EMPTY_LIST_EXP_H

