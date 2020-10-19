#include "gtest/gtest.h"
#include "../Katas/Katas.h"

TEST(KataTests, TestName) {
	std::string hi("Helllo");
	std::string hi2("3ollleH");
	EXPECT_EQ(spinWords(hi), "ollleH");
	EXPECT_TRUE(true);
}
TEST(KataTests, highAndLow) {
	std::string input("8 3 -5 42 -1 0 0 -9 4 7 4 -4");
	std::string output("42 -9");

	EXPECT_EQ(highAndLow(input), output);
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
TEST(KataTests, DNAStrand) {
	std::string input("CATA");
	std::string output("GTAT");

	EXPECT_EQ(DNAStrand(input), output);
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}