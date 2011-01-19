#include "Reader.hpp"

#include "Recognizer.hpp"
#include "BoolExp.hpp"
#include "SymbolExp.hpp"
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
      return ValExp::Create(boost::lexical_cast<int>(token)); // TODO: handle errors
    }

    // booleans
    if(Recognizer::IsBoolean(token))
    {
      tokens.pop_front();
      if(token == "#t")
      {
        return BoolExp::Create(true);
      }
      if(token == "#f")
      {
        return BoolExp::Create(false);
      }
    }

    // symbols
    if(Recognizer::IsSymbol(token))
    {
      tokens.pop_front();
      return SymbolExp::Create(token);
    }

    // empty lists
    if(Recognizer::IsEmptyList(tokens))
    {
      assert(tokens.front() == "(");
      assert(tokens.back() == ")");
      tokens.pop_front();

      return EmptyListExp::Create();
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

    // lists
    if(Recognizer::IsList(tokens))
    {
      assert(tokens.front() == "(");
      assert(tokens.back() == ")");
      tokens.pop_front();

      return ReadList(tokens);
    }

    return NullExp::Create();
  }

  pExp Reader::ReadList(std::list<std::string>& tokens)
  {
    if(tokens.front() == ")")
    {
      return EmptyListExp::Create();
    }

    return PairExp::Create(Read(tokens), ReadList(tokens));
  }

} // sexp_cpp

