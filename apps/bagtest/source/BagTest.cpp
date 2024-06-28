#include <vector> 
#include <gtest/gtest.h>
#include "bag.hpp"
// TEST: Confirm default constructor behaves correctly
TEST(BagUnitTests, DefaultConstructor) {
	Bag<int> aBag;
	EXPECT_EQ(aBag.size(), 0);
	EXPECT_EQ(aBag.count(42), 0);
}

TEST(BagUnitTests, InsertNewThing) {
	Bag<int> aBag;
	EXPECT_EQ(aBag.size(), 0);
	EXPECT_EQ(aBag.count(10), 0);
	aBag.insert(42);
	EXPECT_EQ(aBag.size(), 1);
	EXPECT_EQ(aBag.count(42), 1);
	aBag.insert(59);
	EXPECT_EQ(aBag.size(), 2);
	EXPECT_EQ(aBag.count(59), 1);
}
