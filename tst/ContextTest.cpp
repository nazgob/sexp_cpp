#include <gtest/gtest.h>
#include "../src/Context.hpp"

using namespace sexp_cpp;

#include <stdexcept>

namespace
{
  TEST(ContextTest, DefineAndLookup)
  {
    Context context;
    context.Define("foo", 1);
    context.Define("bar", 2);

    EXPECT_EQ(1, context.Lookup("foo"));
    EXPECT_EQ(2, context.Lookup("bar"));
  }

  TEST(ContextTest, DoubleDefineIsOK)
  {
    Context context;
    context.Define("foo", 42);
    context.Define("foo", 42);

    EXPECT_EQ(42, context.Lookup("foo"));
  }

  TEST(ContextTest, SetPositive)
  {
    Context context;

    context.Define("foo", 0);
    EXPECT_EQ(0, context.Lookup("foo"));

    context.Set("foo", 43);
    EXPECT_EQ(43, context.Lookup("foo"));
  }

  TEST(ContextTest, SetNegative)
  {
    Context context;

    EXPECT_THROW(context.Set("foo", 42), std::logic_error);
  }

  TEST(ContextTest, LookupOnEmpty)
  {
    Context context;
    EXPECT_THROW(context.Lookup("foobar"), std::runtime_error);
  }

} 

