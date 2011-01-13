#ifndef TOKENIZER_H 
#define TOKENIZER_H

#include <list>
#include <string>
#include <stdexcept>

#include <boost/tokenizer.hpp>

namespace sexp_cpp
{
  class Tokenizer // TODO: 
  {
    public:
      std::list<std::string> Tokenize(const std::string& input)
      {
        std::string code = input;
        if(code.empty())
        {
          throw std::invalid_argument("can't tokenize empty string!");
        }

        typedef boost::tokenizer<boost::char_separator<char> > tokenizer;
        std::string dropped_delimiters = " "; // space
        std::string kept_delimiters = "()'";
        boost::char_separator<char> separators(dropped_delimiters.c_str(), kept_delimiters.c_str());
        tokenizer tokens(code, separators);

        std::list<std::string> list;
        list.insert(list.end(), tokens.begin(), tokens.end());

        return list;
      }

  };

} // sexp_cpp

#endif // TOKENIZER_H

