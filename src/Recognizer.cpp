#include "Recognizer.hpp"

#include <boost/lexical_cast.hpp>
#include <cctype>

namespace sexp_cpp
{

  bool Recognizer::IsInteger(const std::string& token)
  {
    try
    {
      boost::lexical_cast<int>(token);
      return true;
    }
    catch(boost::bad_lexical_cast)
    {
      return false;
    }
  }

  bool Recognizer::IsBoolean(const std::string& token)
  {
    if(token[0] == '#' && (token[1] == 't' || token[1] == 'f') && token.size() == 2)
    {
      return true;
    }

    return false;
  }
  bool Recognizer::IsSymbol(const std::string& token)
  {
    if(isalpha(token[0])) // TODO: '*' '/' '>' '<' '=' '?' '!' can are allowed to?
    {
      return true;
    }

    return false;
  }

  bool Recognizer::IsEmptyList(const std::list<std::string>& tokens)
  {
    if(tokens.size() == 2 && tokens.front() == "(" && tokens.back() == ")") // 2 brackets
    {
      return true;
    }

    return false;
  }

  bool Recognizer::IsList(const std::list<std::string>& tokens)
  {
    if(tokens.size() >= 4 && tokens.front() == "(" && tokens.back() == ")") // 2 brackets + 2 args
    {
      return true;
    }

    return false;
  }

  bool Recognizer::IsQuoted(const std::string& token)
  {
    if(token == "quote" || token[0] == '\'') // TODO: quote has shortcut '
    {
      return true;
    }

    return false;
  }
  
} // sexp_cpp

