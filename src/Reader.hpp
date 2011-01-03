#ifndef READER_HPP
#define READER_HPP

#include <string>
#include <list>

#include <Recognizer.hpp>
#include <Utils.hpp>
#include <ValueExp.hpp>
#include <BoolExp.hpp>

namespace sexp_cpp
{

  class Reader
  {
    public:
      pExp Read(const std::list<std::string>& tokens)
      {
        std::string token = tokens.front();

        if(Recognizer::IsInteger(token))
        {
          return pVal(new ValueExp(boost::lexical_cast<int>(token))); // TODO: handle errors
        }

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

        pExp NullExp;
        return NullExp;
      }
  };

} // sexp_cpp

#endif // READER_HPP

