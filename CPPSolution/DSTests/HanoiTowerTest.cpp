#include <vector>
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../DataStructures/headers/HanoiTowers.h"

using ::testing::ElementsAre;
TEST(HanoiTower, Init) {
	// empty
	Towers Tow;
	//ASSERT_THAT(Tow.A, ElementsAre(4,3,2,1));
}
TEST(HanoiTower, Move) {
	// empty
	Towers Tow;
	ASSERT_THAT(Tow.asvec(Tow.A), ElementsAre(4,3,2,1));
	ASSERT_THAT(Tow.asvec(Tow.B), ElementsAre());
	ASSERT_THAT(Tow.asvec(Tow.C), ElementsAre());
	Tow.mv('A', 'C', Towers::rng{3,1});
	//Tow.mv('A', 'B', Towers::rng{ 2 });
	ASSERT_THAT(Tow.asvec(Tow.A), ElementsAre(4));
	ASSERT_THAT(Tow.asvec(Tow.B), ElementsAre());
	ASSERT_THAT(Tow.asvec(Tow.C), ElementsAre(3,2,1));
}
