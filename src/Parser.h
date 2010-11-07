#ifndef PARSER_H
#define PARSER_H

#include <list>
#include <string>
#include <stdexcept>

#include <boost/lexical_cast.hpp>

#include "../src/SExp.h"
#include "../src/VarExp.h"
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

          token = tokens.front();
          tokens.pop_front();

          pOp op(new AddOperator());

          token = tokens.front();
          tokens.pop_front();
          
          pVar a(new VarExp("a"));
          context.Assign(a, boost::lexical_cast<int>(token));
          
          token = tokens.front();
          tokens.pop_front();
          
          pVar b(new VarExp("b"));
          context.Assign(b, boost::lexical_cast<int>(token));

          SExp* sExp = new SExp(a, b, op);
          int result = sExp->Evaluate(context);

          delete sExp; sExp = NULL;
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
  };

} // sexp_cpp

#endif // PARSER_H

