#include "pch.h"
using ::testing::ElementsAre;

class ArrayRecursiveTest : public ::testing::Test
{
protected:
	void SetUp() override 
	{
		for (int i = 0; i < full.GetSize(); i++) {
			full.Set(i, 0);
			fullIncr.Set(i, i);
			if (i < 4) ott.Set(i,i);
			if (i < 5) five.Set(i,i);
		}


	}
	ArrayRecursive empty;
	ArrayRecursive ott;		// 0,1,2,3
	ArrayRecursive full;		// 0,0,0,0,0,0,0,0,0,0 
	ArrayRecursive fullIncr; // 0,1,2,3,4,5,6,7,8,9
	ArrayRecursive five;		// 0,1,2,3,4
};

TEST_F(ArrayRecursiveTest, Init) {
	// empty
	EXPECT_EQ(empty.GetLength(), 0);
	EXPECT_EQ(empty.GetSize(), 10); 
	ASSERT_THAT(empty.GetVector(), ElementsAre());

	// One Two Three
	EXPECT_EQ(ott.GetLength(), 4);
	EXPECT_EQ(ott.GetSize(), 10); 
	ASSERT_THAT(ott.GetVector(), ElementsAre(0,1,2,3));

	// full
	EXPECT_EQ(full.GetLength(), 10);
	EXPECT_EQ(full.GetSize(), 10); 
	ASSERT_THAT(full.GetVector(), ElementsAre(0,0,0,0,0,0,0,0,0,0));

	// five
	EXPECT_EQ(five.GetLength(), 5);
	EXPECT_EQ(five.GetSize(), 10); 
	ASSERT_THAT(five.GetVector(), ElementsAre(0,1,2,3,4));
}

TEST_F(ArrayRecursiveTest, Insert_empty) { 
	empty.Insert(3, 99); 
	EXPECT_EQ(empty.GetLength(), 4);
	EXPECT_EQ(empty.GetSize(), 10); 
	ASSERT_THAT(empty.GetVector(), ElementsAre(0,0,0,99));
}

TEST_F(ArrayRecursiveTest, Insert_fullIncr) { 
	fullIncr.Insert(3, 99); 
	EXPECT_EQ(fullIncr.GetLength(), 10);
	EXPECT_EQ(fullIncr.GetSize(), 10); 
	ASSERT_THAT(fullIncr.GetVector(), ElementsAre(0,1,2,99,3,4,5,6,7,8));
}

TEST_F(ArrayRecursiveTest, Insert_ott) { 
	ott.Insert(2, 99); 
	EXPECT_EQ(ott.GetLength(), 5);
	EXPECT_EQ(ott.GetSize(), 10); 
	ASSERT_THAT(ott.GetVector(), ElementsAre(0,1,99,2,3));
}
TEST_F(ArrayRecursiveTest, Delete_empty) { 
 // Corner case
}


TEST_F(ArrayRecursiveTest, Delete_fullIncr) {
	fullIncr.Delete(3); 
	EXPECT_EQ(fullIncr.GetLength(), 9);
	EXPECT_EQ(fullIncr.GetSize(), 10); 
	ASSERT_THAT(fullIncr.GetVector(), ElementsAre(0,1,2,4,5,6,7,8,9));
}
TEST_F(ArrayRecursiveTest, Delete_ott) {
	ott.Delete(2);
	EXPECT_EQ(ott.GetLength(), 3);
	EXPECT_EQ(ott.GetSize(), 10);
	ASSERT_THAT(ott.GetVector(), ElementsAre(0, 1, 3));
}
TEST_F(ArrayRecursiveTest, Search) { }
TEST_F(ArrayRecursiveTest, Reverse) { }
TEST_F(ArrayRecursiveTest, Shift) { }
TEST_F(ArrayRecursiveTest, Rotate) { }