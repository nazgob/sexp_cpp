#include <iostream>
#include <string>
#include <sstream>
#include <list>

#include <Tokenizer.hpp>
#include <Lexer.hpp>

int main()
{
  const std::string prompt = "sexp> ";

  while(1)
  {
    // read
    std::cout << prompt;
    std::string input = "";
    getline(std::cin, input);
    std::stringstream instream(input);

    try
    {
      // parse
      sexp_cpp::Tokenizer tokenizer;
      std::list<std::string> list = tokenizer.Tokenize(instream.str());

      // eval
      sexp_cpp::Lexer lexer;
      lexer.LexSubExp(list);

      // print
      std::cout << list.front() << std::endl;
    }
    catch(std::exception& e)
    {
      std::cout << "Sth crashed... " << e.what() << std::endl; 
    }
  }

  return 0;
}

