#ifndef DATAFACTORY_H
#define DATAFACTORY_H

#include "../src/Utils.hpp"
#include "../src/Tokenizer.hpp"
#include "../src/Reader.hpp"

#include <list>
#include <string>

namespace sexp_cpp
{

  class Data
  {
    public:
      static pExp CreateExp(const std::string& code)
      {
        Tokenizer t;
        std::list<std::string> tokens_list = t.Tokenize(code);

        Reader reader;
        return reader.Read(tokens_list);
      }

      static std::list<std::string> CreateList(const std::string& code)
      {
        Tokenizer t;

        std::list<std::string> tokens_list = t.Tokenize(code);
        return tokens_list;
      }
  };

} // sexp_cpp

#endif // DATAFACTORY_H

