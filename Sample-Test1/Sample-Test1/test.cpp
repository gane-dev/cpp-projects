#include "pch.h"
#include "../ConsoleApplication1/arithmetic.h"
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(SquareTests, Square)
{
	EXPECT_EQ(0, square(0));
	EXPECT_EQ(4, square(-2));
}