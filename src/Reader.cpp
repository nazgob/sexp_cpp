#include "Reader.hpp"

#include "Recognizer.hpp"
#include "BoolExp.hpp"
#include "VarExp.hpp"
#include "ValExp.hpp"
#include "EmptyListExp.hpp"
#include "PairExp.hpp"
#include "NullExp.hpp"

namespace sexp_cpp
{

  pExp Reader::Read(std::list<std::string>& tokens)
  {
    std::string token = tokens.front();

    // integers
    if(Recognizer::IsInteger(token))
    {
      tokens.pop_front();
      return pVal(new ValExp(boost::lexical_cast<int>(token))); // TODO: handle errors
    }

    // booleans
    if(Recognizer::IsBoolean(token))
    {
      tokens.pop_front();
      if(token == "#t")
      {
        return pBool(new BoolExp(true));
      }
      if(token == "#f")
      {
        return pBool(new BoolExp(false));
      }
    }

    // symbols
    if(Recognizer::IsSymbol(token))
    {
      tokens.pop_front();
      return pVar(new VarExp(token));
    }

    // empty lists
    if(Recognizer::IsEmptyList(tokens))
    {
      assert(tokens.front() == "(");
      assert(tokens.back() == ")");
      tokens.pop_front();

      return pEList(new EmptyListExp());
    }

    // single quote
    if(Recognizer::IsSingleQuoted(tokens))
    {
      assert(tokens.front() == "'");
      tokens.pop_front(); // drop '
      tokens.push_front("quote");
      tokens.push_front("(");
      tokens.push_back(")");

      return Read(tokens);
    }

    // quoted list
    if(Recognizer::IsQuotedList(tokens))
    {
      assert(tokens.front() == "(");
      assert(tokens.back() == ")");
      tokens.pop_front();

      assert(tokens.front() == "quote");
      tokens.pop_front();

      pExp cdr(Read(tokens));
      return cdr;
    }

    // lists
    if(Recognizer::IsList(tokens))
    {
      assert(tokens.front() == "(");
      assert(tokens.back() == ")");
      tokens.pop_front();

      return ReadList(tokens);
    }

    return pNull(new NullExp());
  }

  pExp Reader::ReadList(std::list<std::string>& tokens)
  {
    if(tokens.front() == ")")
    {
      return pEList(new EmptyListExp());
    }

    pExp car(Read(tokens));
    pExp cdr(ReadList(tokens));

    return pPair(new PairExp(car, cdr));
  }

} // sexp_cpp

