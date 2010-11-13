#include <gtest/gtest.h>

#include "../src/Tokenizer.h"
#include "../src/Utils.h"

using namespace sexp_cpp;

#include <stdexcept>

namespace
{

	TEST(TokenizerTest, EmptyString)
	{
		std::string empty;
		Tokenizer tokenizer;
		EXPECT_THROW(tokenizer.Tokenize(empty), std::invalid_argument);
	}

	TEST(TokenizerTest, SimpleSExp)
	{
		std::string sample = "( + 2 3 )";
		Tokenizer tokenizer;
		std::list<std::string> list = tokenizer.Tokenize(sample);

		EXPECT_EQ(static_cast<size_t>(5), list.size());
		EXPECT_EQ("(", list.front()); list.pop_front();
		EXPECT_EQ("+", list.front()); list.pop_front();
		EXPECT_EQ("2", list.front()); list.pop_front();
		EXPECT_EQ("3", list.front()); list.pop_front();
		EXPECT_EQ(")", list.front()); list.pop_front();
	}

	TEST(TokenizerTest, NestedSExp)
	{
		std::string sample = "( + 1 ( - 4 5 ) )";
		Tokenizer tokenizer;
		std::list<std::string> list = tokenizer.Tokenize(sample);

		EXPECT_EQ(static_cast<size_t>(9), list.size());
		EXPECT_EQ("(", list.front()); list.pop_front();
		EXPECT_EQ("+", list.front()); list.pop_front();
		EXPECT_EQ("1", list.front()); list.pop_front();
		EXPECT_EQ("(", list.front()); list.pop_front();
		EXPECT_EQ("-", list.front()); list.pop_front();
		EXPECT_EQ("4", list.front()); list.pop_front();
		EXPECT_EQ("5", list.front()); list.pop_front();
		EXPECT_EQ(")", list.front()); list.pop_front();
		EXPECT_EQ(")", list.front()); list.pop_front();
	}

}

