#include <vector>
#include <string>
#include <exception>
#include <gtest/gtest.h>
#include "Pair.hpp"
#include "Dictionary.hpp"

// TEST: Confirm default constructor behaves correctly

TEST(DictUnitTests, DefaultConstructor) {
	Dictionary<int,string> * aDict  = new Dictionary<int,string>();
	EXPECT_FALSE(aDict == nullptr);
  EXPECT_TRUE(aDict->empty());
	delete aDict;
}


TEST(DictUnitests, InsertNewThing) {
  Dictionary<int, string> *aDict = new Dictionary<int,string>();
	EXPECT_FALSE(aDict == nullptr);
	EXPECT_EQ(aDict->size(), 0);
  aDict->insert(42, "DummyValue");
	EXPECT_EQ(aDict->size(), 1);
  aDict->insert(59, "DummyValue");
	EXPECT_EQ(aDict->size(), 2);
	delete aDict;

}
