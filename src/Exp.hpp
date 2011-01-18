#ifndef EXP_H
#define EXP_H 

#include <string>
#include "Utils.hpp"

namespace sexp_cpp
{
  class Context;

  class Exp
  {
    public:
      virtual ~Exp() {}
      virtual pExp Evaluate(Context&) const = 0;
      virtual std::string WhoAmI() const = 0;
      virtual std::string Write() const = 0;
      
      virtual pExp Car() const = 0;
      virtual pExp Cdr() const = 0;
  };

} // sexp_cpp

#endif // EXP_H

