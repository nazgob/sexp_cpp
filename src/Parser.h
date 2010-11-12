#ifndef PARSER_H
#define PARSER_H

#include <list>
#include <string>
#include <stdexcept>

#include <boost/lexical_cast.hpp>

#include "../src/SExp.h"
#include "../src/ValueExp.h"
#include "../src/Operator.h"
#include "../src/Context.h"
#include "../src/Utils.h"

namespace sexp_cpp
{

  class Tokenizer // TODO: move it to proper file
  {
  };

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

  class Parser
  {
    public:
      int Parse(std::list<std::string>& tokens)
      {
        Context context;

        if(tokens.empty() == true)
        {
          throw std::invalid_argument("can't parse empty tokens list!");
        }

        std::string token = tokens.front();
        tokens.pop_front();

        if (token == "(")
        {
          std::string token;

          token = GetNextToken(tokens);

          pOp op = OperatorFactory::getOperator(token);

          token = GetNextToken(tokens);

          pVal lhs = ExpFactory::getValueExp(token);

          token = GetNextToken(tokens); // TODO: consider check for "(" and run recursion here!

          if (token == "(") // ( + 1 ( - 4 5 ) )
          {
            token = GetNextToken(tokens); // op
            pOp op = OperatorFactory::getOperator(token);

            token = GetNextToken(tokens); // lhs
            pVal lhs = ExpFactory::getValueExp(token);

            token = GetNextToken(tokens); // rhs
            pVal rhs = ExpFactory::getValueExp(token);

            pSExp sExp = ExpFactory::getSExp(lhs, rhs, op);

            token = GetNextToken(tokens); // eat )

            tokens.push_front(boost::lexical_cast<std::string>(sExp->Evaluate(context)));
            token = GetNextToken(tokens); // eat sexp result
          }

          pVal rhs = ExpFactory::getValueExp(token);

          pSExp sExp = ExpFactory::getSExp(lhs, rhs, op);

          token = GetNextToken(tokens); // eat )

          return sExp->Evaluate(context);
        }
        else if(token == ")")
        {
          throw std::invalid_argument("can't parse ')' as first token!");
        }
        else
        {
          throw std::invalid_argument("TODO!");
        }
      }

      std::string GetNextToken(std::list<std::string>& tokens)
      {
        std::string token = tokens.front();
        tokens.pop_front();
        return token;
      }
  };

} // sexp_cpp

#endif // PARSER_H

