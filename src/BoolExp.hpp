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

      virtual pExp Evaluate(Context&) const {return pExp(new BoolExp(mValue));} //TODO: fix it!

      virtual std::string WhoAmI() const {return "BoolExp";}
      
      virtual std::string Write() const
      {
        return mValue ? "#t" : "#f";
      }

    protected:
      bool mValue; 
  };

} // sexp_cpp

#endif // BOOL_EXP_H

