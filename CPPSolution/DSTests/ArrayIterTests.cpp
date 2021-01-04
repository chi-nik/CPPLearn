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
	ott.Insert(2, 99); 
	EXPECT_EQ(ott.GetLength(), 5);
	EXPECT_EQ(ott.GetSize(), 10); 
	ASSERT_THAT(ott.GetVector(), ElementsAre(0,1,99,2,3));
}
TEST_F(ArrayIterTest, Delete_empty) { 
 // Corner case
	FAIL() << "Not implemented";
}


TEST_F(ArrayIterTest, Delete_fullIncr) {
	fullIncr.Delete(3); 
	EXPECT_EQ(fullIncr.GetLength(), 9);
	EXPECT_EQ(fullIncr.GetSize(), 10); 
	ASSERT_THAT(fullIncr.GetVector(), ElementsAre(0,1,2,4,5,6,7,8,9));
}
TEST_F(ArrayIterTest, Delete_ott) {
	ott.Delete(2);
	EXPECT_EQ(ott.GetLength(), 3);
	EXPECT_EQ(ott.GetSize(), 10);
	ASSERT_THAT(ott.GetVector(), ElementsAre(0, 1, 3));
}
TEST_F(ArrayIterTest, Search_empty) 
{ 
	EXPECT_EQ(empty.Search(3), -1); 
}
TEST_F(ArrayIterTest, Search_fullIncr) 
{ 
	EXPECT_EQ(fullIncr.Search(3), 3); 
	EXPECT_EQ(fullIncr.Search(9), 9); 
}
TEST_F(ArrayIterTest, Search_ott) 
{ 
	EXPECT_EQ(ott.Search(1), 1); 
	EXPECT_EQ(ott.Search(9), -1); 
}
TEST_F(ArrayIterTest, Reverse_empty) 
{ 
	empty.Reverse();
	EXPECT_EQ(empty.GetLength(), 0);
	EXPECT_EQ(empty.GetSize(), 10); 
	ASSERT_THAT(empty.GetVector(), ElementsAre());
}
TEST_F(ArrayIterTest, Reverse_fullIncr) 
{ 
	fullIncr.Reverse(); 
	EXPECT_EQ(fullIncr.GetLength(), 10);
	EXPECT_EQ(fullIncr.GetSize(), 10); 
	ASSERT_THAT(fullIncr.GetVector(), ElementsAre(9,8,7,6,5,4,3,2,1,0));
}
TEST_F(ArrayIterTest, Reverse_ott) 
{ 
	ott.Reverse(); 
	EXPECT_EQ(ott.GetLength(), 4);
	EXPECT_EQ(ott.GetSize(), 10); 
	ASSERT_THAT(ott.GetVector(), ElementsAre(3,2,1,0));
}
TEST_F(ArrayIterTest, Shift_empty) 
{ 
	empty.Shift(1);
	EXPECT_EQ(empty.GetLength(), 1);
	EXPECT_EQ(empty.GetSize(), 10); 
	ASSERT_THAT(empty.GetVector(), ElementsAre(0));
}
TEST_F(ArrayIterTest, Shift_fullIncr) 
{ 
	fullIncr.Shift(2); 
	EXPECT_EQ(fullIncr.GetLength(), 10);
	EXPECT_EQ(fullIncr.GetSize(), 10); 
	ASSERT_THAT(fullIncr.GetVector(), ElementsAre(0,0,0,1,2,3,4,5,6,7));
}
TEST_F(ArrayIterTest, Shift_ott) 
{ 
	ott.Shift(1); 
	EXPECT_EQ(ott.GetLength(), 5);
	EXPECT_EQ(ott.GetSize(), 10); 
	ASSERT_THAT(ott.GetVector(), ElementsAre(0,0,1,2,3));
}
TEST_F(ArrayIterTest, isSorted_empty) 
{ 
	empty.Shift(1);
	EXPECT_EQ(empty.GetLength(), 1);
	EXPECT_EQ(empty.GetSize(), 10); 
	ASSERT_THAT(empty.GetVector(), ElementsAre(0));
	EXPECT_EQ(ott.isSorted(), true);
}
TEST_F(ArrayIterTest, isSorted_fullIncr) 
{ 
	fullIncr.Shift(2); 
	EXPECT_EQ(fullIncr.GetLength(), 10);
	EXPECT_EQ(fullIncr.GetSize(), 10); 
	ASSERT_THAT(fullIncr.GetVector(), ElementsAre(0,0,0,1,2,3,4,5,6,7));
	fullIncr.Set(0, 3);
	EXPECT_EQ(fullIncr.isSorted(), false);
}
TEST_F(ArrayIterTest, isSorted_ott)
{ 
 
	ott.Shift(1); 
	EXPECT_EQ(ott.GetLength(), 5);
	EXPECT_EQ(ott.GetSize(), 10); 
	ASSERT_THAT(ott.GetVector(), ElementsAre(0,0,1,2,3)); 
	ott.Set(2, 2);
	EXPECT_EQ(ott.isSorted(), true);
	ott.Insert(0, 2);
	EXPECT_EQ(ott.isSorted(), false);

}
TEST_F(ArrayIterTest, Rotate) { FAIL() << " Not Implemented"; }
TEST_F(ArrayIterTest, Merge_ott)
{ 
 
	ott.Merge(fullIncr); 
	EXPECT_EQ(ott.GetLength(), 14);
	EXPECT_EQ(ott.GetSize(), 20); 
	ASSERT_THAT(ott.GetVector(), ElementsAre(0,0,1,1,2,2,3,3,4,5,6,7,8,9)); 
}
TEST_F(ArrayIterTest, Merge_fullIncr)
{ 
 
	fullIncr.Merge(ott); 
	EXPECT_EQ(fullIncr.GetLength(), 14);
	EXPECT_EQ(fullIncr.GetSize(), 20); 
	ASSERT_THAT(fullIncr.GetVector(), ElementsAre(0,0,1,1,2,2,3,3,4,5,6,7,8,9)); 
}
TEST_F(ArrayIterTest, Merge_five)
{ 
 
	five.Merge(five); 
	EXPECT_EQ(five.GetLength(), 10);
	EXPECT_EQ(five.GetSize(), 20); 
	ASSERT_THAT(five.GetVector(), ElementsAre(0,0,1,1,2,2,3,3,4,4)); 
}
TEST_F(ArrayIterTest, Merge_empty)
{ 
 
	five.Merge(empty); 
	EXPECT_EQ(five.GetLength(), 5);
	EXPECT_EQ(five.GetSize(), 20); 
	ASSERT_THAT(five.GetVector(), ElementsAre(0,1,2,3,4)); 
}
