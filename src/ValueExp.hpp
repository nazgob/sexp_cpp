#ifndef VALUE_EXP_H
#define VALUE_EXP_H 

#include "Exp.hpp"

#include <string>
#include <boost/lexical_cast.hpp>

namespace sexp_cpp
{
  class Context;

  class ValueExp : public Exp // TODO: change name to ValExp to be consistent with VarExp
  {
    public:
      ValueExp(int value) : mValue(value) {}
      virtual ~ValueExp() {}

      virtual int Evaluate(Context&) const {return mValue;}

      virtual std::string WhoAmI() const {return "ValueExp";}
      
      virtual std::string Write() const
      {
        return boost::lexical_cast<std::string>(mValue);
      }

    protected:
      int mValue; //TODO: refactor to T type for more types
  };

} // sexp_cpp

#endif // VALUE_EXP_H

