#ifndef READER_HPP
#define READER_HPP

#include <string>
#include <list>

#include <Recognizer.hpp>
#include <Utils.hpp>
#include <ValueExp.hpp>
#include <BoolExp.hpp>
#include <EmptyListExp.hpp>

namespace sexp_cpp
{

  class Reader
  {
    public:
      pExp Read(const std::list<std::string>& tokens)
      {
        std::string token = tokens.front();

        // integers
        if(Recognizer::IsInteger(token))
        {
          return pVal(new ValueExp(boost::lexical_cast<int>(token))); // TODO: handle errors
        }

        // booleans
        if(Recognizer::IsBoolean(token))
        {
          if(token == "#t")
          {
            return pBool(new BoolExp(true));
          }
          if(token == "#f")
          {
            return pBool(new BoolExp(false));
          }
        }

        // empty lists
        if(Recognizer::IsEmptyList(token))
        {
          return pEList(new EmptyListExp());
        }

        pExp NullExp;
        return NullExp;
      }
  };

} // sexp_cpp

#endif // READER_HPP

