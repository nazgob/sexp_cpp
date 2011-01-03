#ifndef UTILS_H
#define UTILS_H

#include <boost/shared_ptr.hpp>

namespace sexp_cpp
{
  class Exp;
  class Operator;
  class VarExp;
  class ValueExp;
  class BoolExp;
  class SExp;

  typedef boost::shared_ptr<Exp> pExp;
  typedef boost::shared_ptr<Operator> pOp;
  typedef boost::shared_ptr<VarExp> pVar;
  typedef boost::shared_ptr<ValueExp> pVal;
  typedef boost::shared_ptr<BoolExp> pBool;
  typedef boost::shared_ptr<SExp> pSExp;
} // sexp_cpp

#endif // UTILS_H
