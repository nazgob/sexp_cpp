#ifndef VAL_EXP_H
#define VAL_EXP_H 

#include "Exp.hpp"

#include <string>
#include <boost/lexical_cast.hpp>

namespace sexp_cpp
{
  class Context;

  class ValExp : public Exp
  {
    public:
      ValExp(int value) : mVal(value) {}
      virtual ~ValExp() {}

      virtual pExp Evaluate(Context&) const {return pExp(new ValExp(mVal));} // TODO: fix it 

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

