#ifndef OPERATOR_H
#define OPERATOR_H

#include "Exp.hpp"
#include "Utils.hpp"

#include <cstddef>
#include <stdexcept>
#include <cassert>

namespace sexp_cpp
{
  class Context;

  class Operator
  {
    public:
      virtual ~Operator() {}
      virtual int Evaluate(pExp, pExp, Context&) const = 0;
      virtual std::string WhoAmI() const = 0;
  };

  class NullOperator : public Operator
  {
    public:
      virtual ~NullOperator() {}
      int Evaluate(pExp, pExp, Context&) const
      {
        throw std::logic_error("operator not defined!");
      }
      virtual std::string WhoAmI() const {return "NullOperator";}
  };

  class BinaryOperator : public Operator
  {
    public:
      virtual ~BinaryOperator() {}
      virtual int Evaluate(pExp, pExp, Context&) const = 0;
      virtual std::string WhoAmI() const = 0;
  };

  class SubOperator : public BinaryOperator
  {
    public:
      virtual ~SubOperator() {}
      virtual int Evaluate(pExp lhs, pExp rhs, Context& context) const 
      {
        assert(NULL != lhs);
        assert(NULL != rhs);
        return (lhs->Evaluate(context) - rhs->Evaluate(context));
      }
      virtual std::string WhoAmI() const {return "SubOperator";}
  };

  class AddOperator : public BinaryOperator
  {
    public:
      virtual ~AddOperator() {}
      virtual int Evaluate(pExp lhs, pExp rhs, Context& context) const
      {
        assert(NULL != lhs);
        assert(NULL != rhs);
        return (lhs->Evaluate(context) + rhs->Evaluate(context));
      }
      virtual std::string WhoAmI() const {return "AddOperator";}
  };

} // sexp_cpp

#endif // OPERATOR_H

