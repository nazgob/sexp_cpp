#ifndef VALUE_EXP_H
#define VALUE_EXP_H 

#include "Exp.h"
#include <string>

namespace sexp_cpp
{
  class Context;

  class ValueExp : public Exp
  {
    public:
      ValueExp(int value) : mValue(value) {}
      virtual ~ValueExp() {}

      virtual int Evaluate(Context&) const {return mValue;}

      virtual std::string WhoAmI() const {return "ValueExp";}
    protected:
      int mValue; //TODO: refactor to T type for more types
  };

} // sexp_cpp

#endif // VALUE_EXP_H

