#include <iostream>
#include <string>
#include <sstream>
#include <list>

#include <Exp.hpp>
#include <Context.hpp>
#include <Tokenizer.hpp>
//#include <Lexer.hpp>

#include <Reader.hpp>
#include <Utils.hpp>

using namespace sexp_cpp;

int main()
{
  const std::string prompt = "sexp> ";
  Context context;

  // read-eval-print-loop => REPL
  
  while(1)
  {
    // input
    std::cout << prompt;
    std::string input = "";
    getline(std::cin, input);
    std::stringstream instream(input);

    try
    {
      // parse
      Tokenizer tokenizer;
      std::list<std::string> list = tokenizer.Tokenize(instream.str());

      // read
      Reader reader;
      pExp exp = reader.Read(list);
      assert(NULL != exp.get());

      // eval
      std::cout << exp->Evaluate(context) << std::endl; // TODO: we use self-evaluating stuff just for now

      // print
      std::cout << exp->Write() << std::endl;

      // eval
      //sexp_cpp::Lexer lexer;
      //lexer.LexSubExp(list);

    }
    catch(std::exception& e)
    {
      std::cout << "Sth crashed... " << e.what() << std::endl; 
    }
  }

  return 0;
}

