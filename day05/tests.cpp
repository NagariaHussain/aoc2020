#include <gtest/gtest.h>
#include "solution.h"


TEST(getIDFunc, boarding_passes) {
   ASSERT_EQ(567, getID("BFFFBBFRRR"));
}

TEST(getIDFunc, boarding_passes2) {
   ASSERT_EQ(119, getID("FFFBBBFRRR"));
}


TEST(getIDFunc, boarding_passes3) {
   ASSERT_EQ(820, getID("BBFFBBFRLL"));
}



int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);

   if (RUN_ALL_TESTS() == 0) {
      std::cout << "All tests passed.\n";
   }

   init();
   return 0;
}
