#include <gtest/gtest.h>
#include "solution.h"


TEST(PART1, COUNT_BAGS_TEST) {
   ASSERT_EQ(4, countBags1("day07/test1.txt"));
}

TEST(PART2, COUNT_BAGS_TEST) {
   ASSERT_EQ(126, countBags2("day07/test2.txt"));
}



int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);

   if (RUN_ALL_TESTS() == 0) {
      std::cout << "All tests passed.\n";
   }

   init();
   return 0;
}
