#ifndef UTILS_H
#define UTILS_H

#include <boost/shared_ptr.hpp>

namespace sexp_cpp
{
  class Exp;
  class Operator;
  class SymbolExp;
  class ValExp;
  class BoolExp;
  class NullExp;
  class EmptyListExp;
  class PairExp;
  class SExp;

  typedef boost::shared_ptr<Exp> pExp;
  typedef boost::shared_ptr<Operator> pOp;
  typedef boost::shared_ptr<SymbolExp> pSymbol;
  typedef boost::shared_ptr<ValExp> pVal;
  typedef boost::shared_ptr<NullExp> pNull;
  typedef boost::shared_ptr<BoolExp> pBool;
  typedef boost::shared_ptr<EmptyListExp> pEList;
  typedef boost::shared_ptr<PairExp> pPair;
  typedef boost::shared_ptr<SExp> pSExp;

} // sexp_cpp

#endif // UTILS_H
