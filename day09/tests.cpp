#include <gtest/gtest.h>
#include "solution.h"


TEST(PART1, pre5) {
   ASSERT_EQ(anomalyNum("day09/test1.txt", 5), 127);
}

TEST(PART2, contiguos) {
   ASSERT_EQ(findContiguous("day09/test1.txt", 5), 62);
}


int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);

   if (RUN_ALL_TESTS() == 0) {
      std::cout << "All tests passed.\n";
   }

   init();
   return 0;
}
