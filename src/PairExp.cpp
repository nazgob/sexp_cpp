#include "PairExp.hpp"
#include "Context.hpp"
#include "SymbolExp.hpp"
#include "BoolExp.hpp"
#include "Func.hpp"

namespace sexp_cpp
{

  //TODO: make symbols like quote or if and add them to context
  // then consider pulling making use of global eval method
  pExp PairExp::Evaluate(Context& context) const
  {
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
    if(mCar->Write() == "if")
    {
      if(cadr(this)->Write() != "#f")
      {
        //TODO: this eval call is instead of proper tail recursion!
        return caddr(this)->Evaluate(context); 
      }
      else if(caddr(this)->Write() == "()")
      {
        return BoolExp::Create(false);
      }
      else
      {
        //TODO: this eval call is instead of proper tail recursion!
        return cadddr(this)->Evaluate(context);
      }
    }
    if(mCar->WhoAmI() == "SymbolExp")
    {
      pFunc function = context.LookupFunc(mCar->Write());
      function->SetList(mCdr);
      return function->Evaluate(context);
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

