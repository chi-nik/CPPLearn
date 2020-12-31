#include "pch.h"
//#include "gmock/gmock.h"
class ArrayAtomTest : public ::testing::Test
{
protected:
	void SetUp() override 
	{
		a1.Insert(0, 1);
		a1.Insert(0, 2);
		a1.Insert(0, 3);
		a1.Insert(0, 4);

		a2.Insert(0, 1);
		a2.Insert(0, 2);
		a2.Insert(0, 3);
		a2.Insert(0, 4);


	}
	ArrayAtom a1;
	ArrayAtom a2;
};

TEST_F(ArrayAtomTest, Inti) {
	EXPECT_EQ(a1.GetLength(), 4);
	EXPECT_EQ(a1.GetSize(), 4);
//	int res[] = { 1,2,3,4 };
//	EXPECT_EQ(a1.GetArray(), res);
}