#ifndef EXP_H
#define EXP_H 

#include <string>

namespace sexp_cpp
{
  class Context;

  class Exp
  {
    public:
      virtual ~Exp() {}
      virtual int Evaluate(Context&) const = 0;
      virtual std::string WhoAmI() const = 0;
  };

} // sexp_cpp

#endif // EXP_H

