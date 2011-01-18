#ifndef PAIR_EXP_H
#define PAIR_EXP_H 

#include "Exp.hpp"
#include "Utils.hpp"

#include <cassert>
#include <string>
#include <sstream>

namespace sexp_cpp
{
  class Context;

  class PairExp : public Exp 
  {
    public:
      PairExp(pExp car, pExp cdr)
        : mCar(car), mCdr(cdr)
      {
        assert(NULL != mCar);
        assert(NULL != mCdr);
      }
      virtual ~PairExp() {}
      
      static pExp Create(pExp car, pExp cdr) { return pExp(new PairExp(car, cdr));}

      virtual pExp Evaluate(Context&) const;

      virtual std::string WhoAmI() const {return "PairExp";}

      virtual std::string Write() const;

      virtual pExp Car() const {return mCar;}
      virtual pExp Cdr() const {return mCdr;}

    protected:
      pExp mCar;
      pExp mCdr;
  };

} // sexp_cpp

#endif // PAIR_EXP_H

