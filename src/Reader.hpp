#ifndef READER_HPP
#define READER_HPP

#include <string>
#include <list>

#include <Recognizer.hpp>
#include <Utils.hpp>
#include <ValueExp.hpp>
#include <BoolExp.hpp>
#include <EmptyListExp.hpp>
#include <PairExp.hpp>

namespace sexp_cpp
{

  class Reader
  {
    public:
      pExp Read(std::list<std::string>& tokens)
      {
        std::string token = tokens.front();

        // integers
        if(Recognizer::IsInteger(token))
        {
          tokens.pop_front();
          return pVal(new ValueExp(boost::lexical_cast<int>(token))); // TODO: handle errors
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

        // empty lists
        if(Recognizer::IsEmptyList(token))
        {
          tokens.pop_front();
          return pEList(new EmptyListExp());
        }

        // lists
        if(Recognizer::IsList(tokens))
        {
          assert(tokens.front() == "(");
          tokens.pop_front();

          return ReadList(tokens);
        }

        pExp NullExp;
        return NullExp;
      }

      pExp ReadList(std::list<std::string>& tokens)
      {
        if(tokens.front() == ")")
        {
          return pEList(new EmptyListExp());
        }

        pExp car(Read(tokens));
        pExp cdr(ReadList(tokens));

        return pPair(new PairExp(car, cdr));
      }
  };

} // sexp_cpp

#endif // READER_HPP

