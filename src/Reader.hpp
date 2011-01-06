#ifndef READER_HPP
#define READER_HPP

#include <string>
#include <list>

#include "Utils.hpp"

namespace sexp_cpp
{

  class Reader
  {
    public:
      pExp Read(std::list<std::string>& tokens);

      pExp ReadList(std::list<std::string>& tokens);
  };

} // sexp_cpp

#endif // READER_HPP

