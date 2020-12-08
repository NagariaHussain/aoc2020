#include <gtest/gtest.h>
#include "solution.h"


TEST(PART1, TEST_ACC) {
   ASSERT_EQ(5, getAccum1("day08/test1.txt"));
}

TEST(PART2, TEST_ACC) {
   ASSERT_EQ(8, getAccum2("day08/test1.txt"));
}




int main(int argc, char **argv) {


   init();

   testing::InitGoogleTest(&argc, argv);

   if (RUN_ALL_TESTS() == 0) {
      std::cout << "All tests passed.\n";
   }

   return 0;
}
