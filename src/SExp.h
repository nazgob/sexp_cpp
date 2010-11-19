#ifndef SEXP_H
#define SEXP_H

#include "Exp.h"
#include "Operator.h"
#include "Context.h"
#include "Utils.h"

#include <cassert>
#include <string>

namespace sexp_cpp
{

  class SExp : public Exp
  {
    public:
      SExp(pExp lhs, pExp rhs, pOp op)
        : mLhs(lhs), mRhs(rhs), mOp(op)
      {
        assert(NULL != lhs);
        assert(NULL != rhs);
        assert(NULL != op);
      }
      virtual ~SExp() {}

      virtual int Evaluate(Context& context) const
      {
        return mOp->Evaluate(mLhs, mRhs, context);
      }

      virtual std::string WhoAmI() const {return "SExp";}

    protected:
      pExp mLhs;
      pExp mRhs;
      pOp mOp;
  };

} // sexp_cpp

#endif // SEXP_H

