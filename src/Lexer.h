#ifndef LEXER_H
#define LEXER_H

#include <list>
#include <string>
#include <stdexcept>

#include <boost/lexical_cast.hpp>

#include "../src/SExp.h"
#include "../src/ValueExp.h"
#include "../src/Operator.h"
#include "../src/Utils.h"

namespace sexp_cpp
{

  class Formater // TODO: this will convert SExp to format (op lhs, rhs)
  {
  };

  class OperatorFactory
  {
    public:
      static pOp getOperator(const std::string& token)
      {
        pOp op;
        if(token == "+")
        {
          op = pOp(new AddOperator());
        }
        else if(token == "-")
        {
          op = pOp(new SubOperator());
        }
        else
        {
          throw std::invalid_argument("unknown operator: " + token);
        }
        return  op;
      }
  };

  class ExpFactory
  {
    public:
      static pVal getValueExp(const std::string& token)
      {
        return pVal(new ValueExp(boost::lexical_cast<int>(token)));
      }

      static pSExp getSExp(pExp lhs, pExp rhs, pOp op)
      {
        return pSExp(new SExp(lhs, rhs, op));
      }
  };

  class Lexer
  {
    public:
      int Lex(std::list<std::string>& tokens);

      void LexSubExp(std::list<std::string>& tokens);

      std::string GetNextToken(std::list<std::string>& tokens);
  };

} // sexp_cpp

#endif // LEXER_H

