#ifndef RECOGNIZER_HPP
#define RECOGNIZER_HPP

#include <Recognizer.hpp>

#include <string>
#include <boost/lexical_cast.hpp>

//TODO: think over error handling here

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

    static bool IsBoolean(const std::string& token)
    {
      if(token[0] == '#' && (token[1] == 't' || token[1] == 'f') && token.size() == 2)
      {
        return true;
      }

      return false;
    }

    static bool IsEmptyList(const std::string& token)
    {
      if(token[0] == '(' && token[1] == ')' && token.size() == 2)
      {
        return true;
      }
      
      return false;
    }

    static bool IsList(const std::list<std::string>& tokens)
    {
      if(tokens.front() == "(" && tokens.back() == ")" && tokens.size() >= 4) // 2 brackets + 2 args
      {
        return true;
      }
      
      return false;
    }
};

#endif // RECOGNIZER_HPP

