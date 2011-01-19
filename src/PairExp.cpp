#include "PairExp.hpp"
#include "Context.hpp"
#include "SymbolExp.hpp"

namespace sexp_cpp
{

  #define car(exp) exp->Car()
  #define cdr(exp) exp->Cdr()

  #define caar(exp) car(car(exp))
  #define cddr(exp) cdr(cdr(exp))

  #define cdar(exp) cdr(car(exp))
  #define cadr(exp) car(cdr(exp))

  #define caddr(exp) car(cdr(cdr(exp)))

  pExp PairExp::Evaluate(Context& context) const
  {
    if(mCar->Write() == "quote")
    {
      return mCdr->Car();
    }
    if(mCar->Write() == "define")
    {
      context.Define(cadr(this)->Write(), caddr(this));
      return SymbolExp::Create("ok");
    }
    if(mCar->Write() == "set!")
    {
      context.Set(cadr(this)->Write(), caddr(this));
      return SymbolExp::Create("ok");
    }

    return Create(mCar, mCdr);
  }

  std::string PairExp::Write() const
  {
    std::stringstream ss;
    std::string car = mCar->Write();
    std::string cdr = mCdr->Write();

    if(cdr.empty())
    {
      ss << car;
    }
    else
    {
      ss << car 
        << " "
        << cdr;
    }

    return ss.str();
  }

} // sexp_cpp

