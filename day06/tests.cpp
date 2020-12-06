#include <gtest/gtest.h>
#include "solution.h"


TEST(DAY5, PART1) {
   ASSERT_EQ(11, countPart1("day5/test1.txt"));
}

TEST(DAY5, PART2) {
   ASSERT_EQ(6, countPart2("day5/test2.txt"));
}


int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);

   if (RUN_ALL_TESTS() == 0) {
      std::cout << "All tests passed.\n";
   }

   init();
   return 0;
}
