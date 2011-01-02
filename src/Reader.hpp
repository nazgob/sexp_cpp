#ifndef READER_HPP
#define READER_HPP

#include <string>
#include <list>

#include <Recognizer.hpp>
#include <Utils.hpp>
#include <ValueExp.hpp>

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

      }
  };

} // sexp_cpp

#endif // READER_HPP

