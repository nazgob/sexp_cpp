#include "PairExp.hpp"
#include "Context.hpp"
#include "SymbolExp.hpp"
#include "BoolExp.hpp"
#include "Func.hpp"

namespace sexp_cpp
{

  pExp PairExp::Evaluate(Context& context) const
  {
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

