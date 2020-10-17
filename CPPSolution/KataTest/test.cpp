#include "gtest/gtest.h"
#include "../Katas/Katas.h"
TEST(TestCaseName, TestName) {
	std::string hi("Helllo");
	std::string hi2("3ollleH");
  EXPECT_EQ(spinWords(hi), hi2);
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}