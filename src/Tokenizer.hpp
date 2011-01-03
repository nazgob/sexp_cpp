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
        std::string code = input;
        if(code.empty())
        {
          throw std::invalid_argument("can't tokenize empty string!");
        }

        //replace(code, "(", " ( ");
        //replace(code, ")", " ) ");

        std::list<std::string> list;
        std::istringstream ss(code);
        list.insert(list.end(),
                    std::istream_iterator<std::string>(ss),
                    std::istream_iterator<std::string>());

        return list;
      }

    //private:
      //void replace(std::string& string, const std::string& from, const std::string& to)
      //{
        //size_t i = 0;
        //size_t next = 0;
        //while ((next = string.find(from, i)) != std::string::npos)
        //{
          //string.replace(next, from.size(), to);
          //i = next + to.size(); 
        //}
      //}

  };

} // sexp_cpp

#endif // TOKENIZER_H

