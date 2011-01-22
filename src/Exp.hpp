#ifndef EXP_H
#define EXP_H 

#include "Utils.hpp"
#include <string>
#include <stdexcept>

namespace sexp_cpp
{
  class Context;
  class NullExp;

  class Exp
  {
    public:
      virtual ~Exp() {}
      virtual pExp Evaluate(Context&) const = 0;
      virtual std::string WhoAmI() const = 0;
      virtual std::string Write() const = 0;
      
      virtual pExp Car() const {throw std::logic_error("Exp::Car() called!");}
      virtual pExp Cdr() const {throw std::logic_error("Exp::Cdr() called!");}
  };

} // sexp_cpp

#endif // EXP_H

