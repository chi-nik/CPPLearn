#include "pch.h"
using ::testing::ElementsAre;

class ArrayIterTest : public ::testing::Test
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
	ArrayIter empty;
	ArrayIter ott;		// 0,1,2,3
	ArrayIter full;		// 0,0,0,0,0,0,0,0,0,0 
	ArrayIter fullIncr; // 0,1,2,3,4,5,6,7,8,9
	ArrayIter five;		// 0,1,2,3,4
};

TEST_F(ArrayIterTest, Init) {
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

TEST_F(ArrayIterTest, Insert_empty) { 
	empty.Insert(3, 99); 
	EXPECT_EQ(empty.GetLength(), 4);
	EXPECT_EQ(empty.GetSize(), 10); 
	ASSERT_THAT(empty.GetVector(), ElementsAre(0,0,0,99));
}

TEST_F(ArrayIterTest, Insert_fullIncr) { 
	fullIncr.Insert(3, 99); 
	EXPECT_EQ(fullIncr.GetLength(), 10);
	EXPECT_EQ(fullIncr.GetSize(), 10); 
	ASSERT_THAT(fullIncr.GetVector(), ElementsAre(0,1,2,99,3,4,5,6,7,8));
}

TEST_F(ArrayIterTest, Insert_ott) { 
	empty.Insert(2, 99); 
	EXPECT_EQ(empty.GetLength(), 5);
	EXPECT_EQ(empty.GetSize(), 10); 
	ASSERT_THAT(empty.GetVector(), ElementsAre(0,1,99,2,3));
}
TEST_F(ArrayIterTest, Delete) { }
TEST_F(ArrayIterTest, Search) { }
TEST_F(ArrayIterTest, Reverse) { }
TEST_F(ArrayIterTest, Shift) { }
TEST_F(ArrayIterTest, Rotate) { }
