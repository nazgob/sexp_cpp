#ifndef REPL_HPP
#define REPL_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <list>

#include "Exp.hpp"
#include "Context.hpp"
#include "Tokenizer.hpp"
#include "Reader.hpp"
#include "Utils.hpp"

namespace sexp_cpp
{
  Context context;

  pExp read(std::stringstream& ss)
  {
    pExp exp;
    try
    {
      Tokenizer tokenizer;
      std::list<std::string> tokens = tokenizer.Tokenize(ss.str());
      Reader reader;
      exp = reader.Read(tokens);

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

  std::string print(pExp exp)
  {
    try
    {
      if(exp->WhoAmI() == "PairExp")
      {
        std::stringstream ss;
        ss << "(" << exp->Write() << ")";
        return ss.str();
      }

      return exp->Write();
    }
    catch(std::exception& e)
    {
      std::cout << "print crashed => " << e.what() << std::endl;
      return "print crashed...";
    }
  }

} // sexp_cpp

#endif // REPL_HPP

