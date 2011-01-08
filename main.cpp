#include "Repl.hpp"

#include <sstream>
#include <string>
#include <iostream>

using namespace sexp_cpp;

int main()
{
  // (loop (print (eval (read))))
  while(1)
  {
    std::cout << "sexp> ";
    std::string input = "";
    getline(std::cin, input);
    std::stringstream inputStream(input);

    std::cout << print(eval(read(inputStream))) << std::endl;
  }

  return 0;
}

