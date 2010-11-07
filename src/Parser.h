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

  class Formater // TODO: this will format SExp to format (op lhs, rhs)
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

          pVal x(new ValueExp(boost::lexical_cast<int>(token)));

          token = GetNextToken(tokens);

          pVal y(new ValueExp(boost::lexical_cast<int>(token)));

          pSExp sExp(new SExp(x, y, op));
          int result = sExp->Evaluate(context);
          return result;
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

