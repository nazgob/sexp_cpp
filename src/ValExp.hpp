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
      
      static pExp Create(int val) { return pExp(new ValExp(val));}

      static pExp Create(const std::string& val)
      {
        return pExp(new ValExp(boost::lexical_cast<int>(val)));
      }

      virtual pExp Evaluate(Context&) const {return Create(mVal);} 

      virtual std::string WhoAmI() const {return "ValExp";}
      
      virtual std::string Write() const
      {
        return boost::lexical_cast<std::string>(mVal);
      }
      
    protected:
      int mVal;
  };

} // sexp_cpp

#endif // VAL_EXP_H

