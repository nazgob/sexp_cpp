#ifndef QUOTE_H
#define QUOTE_H

#include "Utils.hpp"
#include "Procedure.hpp"

namespace sexp_cpp
{
  
  class Quote : public Procedure
  {
    public:
      virtual ~Quote() {}
      static pProc Create() {return pProc(new Quote());}

      virtual pExp Apply(pExp list) const
      {
        return car(list);
      }
  };

} // sexp_cpp

#endif // QUOTE_H

