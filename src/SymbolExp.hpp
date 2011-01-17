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
      SymbolExp(const std::string& symbolName) : mSymbolName(symbolName) {}
      virtual ~SymbolExp() {}

      virtual pExp Evaluate(Context& context) const;

      //const std::string& getSymbolName() const {return mSymbolName;}

      virtual std::string WhoAmI() const {return "SymbolExp";}
      
      virtual std::string Write() const
      {
        return mSymbolName;
      }

    protected:
      std::string mSymbolName;
  };

} // sexp_cpp

#endif // SYMBOL_EXP_H

