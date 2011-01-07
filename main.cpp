#include "Repl.h"

using namespace sexp_cpp;

int main()
{
  while(1)
  {
    // (loop (print (eval (read))))
    print(eval(read()));
  }

  return 0;
}

