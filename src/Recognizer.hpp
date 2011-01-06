#ifndef RECOGNIZER_HPP
#define RECOGNIZER_HPP

#include <string>
#include <list>

namespace sexp_cpp
{

  class Recognizer
  {
    public:
      static bool IsInteger(const std::string& token);

      static bool IsBoolean(const std::string& token);

      static bool IsEmptyList(const std::string& token);

      static bool IsList(const std::list<std::string>& tokens);
  };

} // sexp_cpp

#endif // RECOGNIZER_HPP

