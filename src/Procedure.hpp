#ifndef PROCEDURE_H
#define PROCEDURE_H

#include "Utils.hpp"

namespace sexp_cpp
{
  
  class Procedure
  {
    public:
      virtual pExp Apply(pExp list) const = 0;
  };

} // sexp_cpp

#endif // PROCEDURE_H

