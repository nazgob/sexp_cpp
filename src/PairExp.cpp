#include "PairExp.hpp"

namespace sexp_cpp
{

  pExp PairExp::Evaluate(Context&) const
  {
    if(mCar->Write() == "quote") // is_quoted
    {
      return mCdr->Car();
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

