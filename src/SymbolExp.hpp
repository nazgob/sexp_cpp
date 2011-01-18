#ifndef SYMBOL_EXP_H
#define SYMBOL_EXP_H

#include "Exp.hpp"
#include <string>

namespace sexp_cpp
{
  class Context;

  class SymbolExp : public Exp
  {
    public:
      SymbolExp(const std::string& name) : mName(name) {}
      virtual ~SymbolExp() {}

      virtual pExp Evaluate(Context& context) const;

      const std::string& GetName() const {return mName;}

      virtual std::string WhoAmI() const {return "SymbolExp";}
      
      virtual std::string Write() const
      {
        return mName;
      }

    protected:
      std::string mName;
  };

} // sexp_cpp

#endif // SYMBOL_EXP_H
