#ifndef BOOL_EXP_H
#define BOOL_EXP_H 

#include "Exp.hpp"
#include "Utils.hpp"

#include <string>
#include <stdexcept>

namespace sexp_cpp
{
  class Context;

  class BoolExp : public Exp 
  {
    public:
      BoolExp(bool value) : mValue(value) {}
      virtual ~BoolExp() {}
      
      static pExp Create(bool value) { return pExp(new BoolExp(value));}

      virtual pExp Evaluate(Context&) const {return Create(mValue);}

      virtual std::string WhoAmI() const {return "BoolExp";}
      
      virtual std::string Write() const
      {
        return mValue ? "#t" : "#f";
      }
      
      virtual pExp Car() const {throw std::logic_error("BoolExp::Car() called!");}
      virtual pExp Cdr() const {throw std::logic_error("BoolExp::Cdr() called!");}

    protected:
      bool mValue; 
  };

} // sexp_cpp

#endif // BOOL_EXP_H

