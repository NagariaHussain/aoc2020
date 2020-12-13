#include <gtest/gtest.h>
#include "solution.h"


TEST(PART1, test_p1_example) {
   ASSERT_EQ(25, getPart1("day12/test1.txt"));
}


TEST(PART2, test_p2_example) {
   ASSERT_EQ(286, getPart2("day12/test1.txt"));
}


int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);

   if (RUN_ALL_TESTS() == 0) {
      std::cout << "All tests passed.\n";
   }

   init();
   return 0;
}
