#ifndef RECOGNIZER_HPP
#define RECOGNIZER_HPP

#include <Recognizer.hpp>

#include <string>
#include <boost/lexical_cast.hpp>

class Recognizer
{
  public:
    static bool IsInteger(const std::string& token)
    {
      try
      {
        boost::lexical_cast<int>(token);
        return true;
      }
      catch(...)
      {
        return false;
      }
    }
};

#endif // RECOGNIZER_HPP

