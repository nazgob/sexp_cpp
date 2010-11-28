#include "Lexer.hpp"
#include "Context.hpp"

namespace sexp_cpp
{

  int Lexer::Lex(std::list<std::string>& tokens)
  {
    if(tokens.empty() == true)
    {
      throw std::invalid_argument("can't parse empty tokens list!");
    }
    if(tokens.front() != "(")
    {
      throw std::invalid_argument("SExp should start with '(' ");
    }

    LexSubExp(tokens);

    std::string token = GetNextToken(tokens);
    return boost::lexical_cast<int>(token);
  }

  void Lexer::LexSubExp(std::list<std::string>& tokens)
  {
    Context context; // TODO: think it over;
    std::string token("");

    token = GetNextToken(tokens);
    assert(token == "(");

    token = GetNextToken(tokens);
    pOp op = OperatorFactory::getOperator(token);

    token = GetNextToken(tokens);
    pVal lhs = ExpFactory::getValueExp(token);

    if(tokens.front() == "(") // this looks bad man but will do for a moment
    {
      LexSubExp(tokens);
    }

    token = GetNextToken(tokens);
    pVal rhs = ExpFactory::getValueExp(token);

    pSExp sExp = ExpFactory::getSExp(lhs, rhs, op);

    token = GetNextToken(tokens);
    assert(token == ")");

    tokens.push_front(boost::lexical_cast<std::string>(sExp->Evaluate(context)));
  }

  std::string Lexer::GetNextToken(std::list<std::string>& tokens)
  {
    std::string token = tokens.front();
    tokens.pop_front();
    return token;
  }

} // sexp_cpp

