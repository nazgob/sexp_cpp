#ifndef TOKENIZER_H 
#define TOKENIZER_H

#include <list>
#include <string>
#include <stdexcept>
#include <sstream>
#include <iterator>

namespace sexp_cpp
{
  class Tokenizer
  {
    public:
      std::list<std::string> Tokenize(const std::string& input)
      {
        if(input.empty())
        {
          throw std::invalid_argument("can't tokenize empty string!");
        }
        std::list<std::string> list;
        std::istringstream ss(input);
        list.insert(list.end(), std::istream_iterator<std::string>(ss), std::istream_iterator<std::string>());
        return list;
      }
  };

} // sexp_cpp

#endif // TOKENIZER_H

