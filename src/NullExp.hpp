#ifndef NULL_EXP_H
#define NULL_EXP_H 

#include "Exp.hpp"
#include "Utils.hpp"

#include <string>
#include <stdexcept>

namespace sexp_cpp
{
  class Context;

  class NullExp : public Exp 
  {
    public:
      NullExp() {}
      virtual ~NullExp() {}
      
      static pExp Create() { return pExp(new NullExp());}

      virtual pExp Evaluate(Context&) const {throw std::logic_error("trying to eval NULL!");}

      virtual std::string WhoAmI() const {return "NullExp";}
      
      virtual std::string Write() const {return "NULL";}
  };

} // sexp_cpp

#endif // NULL_EXP_H

