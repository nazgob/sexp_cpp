#ifndef VAREXP_H
#define VAREXP_H

#include "Exp.h"
#include <string>

namespace sexp_cpp
{
  class Context;

  class VarExp : public Exp
  {
    public:
      VarExp(const std::string& varName) : mVarName(varName) {}
      virtual ~VarExp() {}

      virtual int Evaluate(Context& context) const;

      const std::string& getVarName() const {return mVarName;}

			virtual std::string WhoAmI() const {return "VarExp";}
    protected:
      std::string mVarName;
  };

} // sexp_cpp

#endif // VAREXP_H

