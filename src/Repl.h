#ifndef REPL_H
#define REPL_H

#include <iostream>
#include <string>
#include <sstream>
#include <list>

#include <Exp.hpp>
#include <Context.hpp>
#include <Tokenizer.hpp>

#include <Reader.hpp>
#include <Utils.hpp>

namespace sexp_cpp
{
  Context context;

  pExp read()
  {
    pExp exp;
    try
    {
      std::cout << "sexp> "
      std::string input = "";
      getline(std::cin, input);
      std::stringstream instream(input);

      Tokenizer tokenizer;
      std::list<std::string> tokens = tokenizer.Tokenize(instream.str());

      Reader reader;
      exp = reader.Read(tokens);
      assert(NULL != exp.get());

      return exp;
    }
    catch(std::exception& e)
    {
      std::cout << "read crashed... " << e.what() << std::endl;
      return exp;
    }
  }

  pExp eval(pExp exp)
  {
    try
    {
      return exp->Evaluate(context);
    }
    catch(std::exception& e)
    {
      std::cout << "eval crashed => " << e.what() << std::endl; 
      return exp;
    }
  }

  void print(pExp exp)
  {
    try
    {
      std::cout << exp->Write() << std::endl;
    }
    catch(std::exception& e)
    {
      std::cout << "print crashed => " << e.what() << std::endl; 
    }
  }

} // sexp_cpp

#endif // REPL_H

