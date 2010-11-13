#ifndef DATAFACTORY_H
#define DATAFACTORY_H

#include <list>
#include <string>

namespace sexp_cpp
{

	class DataFactory
	{
		public:
			static void FillWithSimpleSExp(std::string& simple);
			static void FillWithSimpleSExp(std::list<std::string>& simple);

			static void FillWithNestedSExp(std::string& nested);
			static void FillWithNestedSExp(std::list<std::string>& nested);

		private:
			static std::string simpleSExp;
			static std::string nestedSExp;
	};

} // sexp_cpp

#endif // DATAFACTORY_H

