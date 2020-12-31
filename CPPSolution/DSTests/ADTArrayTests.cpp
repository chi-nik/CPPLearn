 #include "pch.h"

using ::testing::ElementsAre;
TEST(ADTArrayTest, Set_Function) {
	ArrayIter empty_array;
	EXPECT_EQ(empty_array.GetLength(), 0);
	EXPECT_EQ(empty_array.GetSize(), 10);

	empty_array.Set(3, 3); 
	ASSERT_THAT(empty_array.GetVector(), ElementsAre(0,0,0,3)); 
	EXPECT_EQ(empty_array.GetLength(), 4);

	empty_array.Set(0, 1); 
	ASSERT_THAT(empty_array.GetVector(), ElementsAre(1,0,0, 3));
	EXPECT_EQ(empty_array.GetLength(), 4);

	empty_array.Set(4, 4); 
	ASSERT_THAT(empty_array.GetVector(), ElementsAre(1,0,0, 3,4));
	EXPECT_EQ(empty_array.GetLength(), 5);

	empty_array.Set(4, 2); 
	ASSERT_THAT(empty_array.GetVector(), ElementsAre(1,0,0, 3,2));
	EXPECT_EQ(empty_array.GetLength(), 5);

	empty_array.Set(10, 2); 
	ASSERT_THAT(empty_array.GetVector(), ElementsAre(1,0,0, 3,2));
	EXPECT_EQ(empty_array.GetLength(), 5);

}

