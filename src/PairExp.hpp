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

      virtual pExp Evaluate(Context&) const;

      virtual std::string WhoAmI() const {return "PairExp";}

      virtual std::string Write() const;

      pExp Car() const {return mCar;}
      pExp Cdr() const {return mCdr;}

    protected:
      pExp mCar;
      pExp mCdr;
  };
 
  // TODO: find a proper place for this stuff 
  //pExp Car(pPair pair)
  //{
    //return pair->Car();
  //}
  
  //pExp Cdr(pPair pair)
  //{
    //return pair->Cdr();
  //}

} // sexp_cpp

#endif // PAIR_EXP_H

