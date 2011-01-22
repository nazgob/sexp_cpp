#ifndef UTILS_H
#define UTILS_H

#include <boost/shared_ptr.hpp>

namespace sexp_cpp
{
  class Exp;
  class SymbolExp;
  class ValExp;
  class BoolExp;
  class NullExp;
  class EmptyListExp;
  class PairExp;
  class AddFunc; //TODO spike, change to generic Func

  typedef boost::shared_ptr<Exp> pExp;
  typedef boost::shared_ptr<SymbolExp> pSymbol;
  typedef boost::shared_ptr<ValExp> pVal;
  typedef boost::shared_ptr<NullExp> pNull;
  typedef boost::shared_ptr<BoolExp> pBool;
  typedef boost::shared_ptr<EmptyListExp> pEList;
  typedef boost::shared_ptr<PairExp> pPair;
  typedef boost::shared_ptr<AddFunc> pFunc;
  
  #define car(exp) exp->Car()
  #define cdr(exp) exp->Cdr()

  #define caar(exp) car(car(exp))
  #define cddr(exp) cdr(cdr(exp))

  #define cdar(exp) cdr(car(exp))
  #define cadr(exp) car(cdr(exp))

  #define caddr(exp) car(cdr(cdr(exp)))
  #define cadddr(exp) car(cdr(cdr(cdr(exp))))


} // sexp_cpp

#endif // UTILS_H
