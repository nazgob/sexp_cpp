#ifndef BOOL_EXP_H
#define BOOL_EXP_H 

#include "Exp.hpp"

#include <string>

namespace sexp_cpp
{
  class Context;

  class BoolExp : public Exp 
  {
    public:
      BoolExp(bool value) : mValue(value) {}
      virtual ~BoolExp() {}

      virtual int Evaluate(Context&) const {return mValue;} // TODO: return bool?

      virtual std::string WhoAmI() const {return "BoolExp";}
    protected:
      bool mValue; 
  };

} // sexp_cpp

#endif // BOOL_EXP_H

