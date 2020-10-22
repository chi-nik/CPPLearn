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
TEST(KataTests, cleanString) {
	std::string input("CA#B");
	std::string output("CB");

	std::string input2("AB##B#C");
	std::string output2("C");
	std::string input3("##B#C##");
	std::string output3("");
	EXPECT_EQ(cleanString(input), output);
	EXPECT_EQ(cleanString(input2), output2);
	EXPECT_EQ(cleanString(input3), output3);
}
TEST(KataTests, range_extraction) {
	std::vector<int> input{ -6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20 };
	std::string output("-6,-3-1,3-5,7-11,14,15,17-20");


	std::vector<int> input2({-3,-2,-1,2,10,15,16,18,19,20});
	std::string output2("-3--1,2,10,15,16,18-20");

	std::vector<int> input3{ -3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20,22,23 };
	std::string output3("-3-1,3-5,7-11,14,15,17-20,22,23");
	std::vector<int> input4{ -3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20,22,23,26 };
	std::string output4("-3-1,3-5,7-11,14,15,17-20,22,23,26");
	EXPECT_EQ(range_extraction(input), output);
	EXPECT_EQ(range_extraction(input2), output2);
	EXPECT_EQ(range_extraction(input3), output3);
	EXPECT_EQ(range_extraction(input4), output4);
}