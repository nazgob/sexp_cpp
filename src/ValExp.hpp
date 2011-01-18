#ifndef VAL_EXP_H
#define VAL_EXP_H 

#include "Exp.hpp"
#include "Utils.hpp"

#include <string>
#include <stdexcept>
#include <boost/lexical_cast.hpp>

namespace sexp_cpp
{
  class Context;

  class ValExp : public Exp
  {
    public:
      ValExp(int value) : mVal(value) {}
      virtual ~ValExp() {}
      
      static pExp Create(int value) { return pExp(new ValExp(value));}

      virtual pExp Evaluate(Context&) const {return Create(mVal);} 

      virtual std::string WhoAmI() const {return "ValExp";}
      
      virtual std::string Write() const
      {
        return boost::lexical_cast<std::string>(mVal);
      }
      
      virtual pExp Car() const {throw std::logic_error("ValExp::Car() called!");}
      virtual pExp Cdr() const {throw std::logic_error("ValExp::Cdr() called!");}

    protected:
      int mVal;
  };

} // sexp_cpp

#endif // VAL_EXP_H

