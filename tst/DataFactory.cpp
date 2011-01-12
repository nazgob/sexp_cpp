#include "DataFactory.hpp"
#include "../src/Tokenizer.hpp"

namespace sexp_cpp
{
  std::string DataFactory::simpleSExp = "(+ 2 3)";
  std::string DataFactory::nestedSExp = "(+ 1 (- 4 5))";

  // TODO: fate of SExp is not decided yet, anyway, stuff below should follow
  // GetList method style
  std::list<std::string> DataFactory::GetList(const std::string& list)
  {
    std::list<std::string> token_list;
    Tokenizer t;

    token_list = t.Tokenize(list);
    return token_list;
  }

  void DataFactory::FillWithSimpleSExp(std::string& simple)
  {
    simple = simpleSExp;
  }

  void DataFactory::FillWithSimpleSExp(std::list<std::string>& simple)
  {
    // ( + 2 3 )
    simple.clear();
    std::string tmp = simpleSExp;

    Tokenizer t;
    simple = t.Tokenize(tmp);
  }

  void DataFactory::FillWithNestedSExp(std::string& nested)
  {
    nested = nestedSExp;
  }

  void DataFactory::FillWithNestedSExp(std::list<std::string>& nested)
  {
    // ( + 1 ( - 4 5 ) )
    // ( + 1 x ) where x = ( - 4 5 )
    nested.clear();

    std::string tmp = nestedSExp;
    Tokenizer t;
    nested = t.Tokenize(tmp);
  }

} // sexp_cpp

