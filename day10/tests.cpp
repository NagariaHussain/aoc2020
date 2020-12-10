#include <gtest/gtest.h>
#include "solution.h"


TEST(PART1, test_p1_example) {
   ASSERT_EQ(35, getPart1("day10/test1.txt"));
}

TEST(PART1, test_p1_example2) {
   ASSERT_EQ(220, getPart1("day10/test2.txt"));
}

TEST(PART2, test_p2_example1) {
    ASSERT_EQ(8, getPart2("day10/test1.txt"));
}

TEST(PART2, test_p2_example2) {
    ASSERT_EQ(19208, getPart2("day10/test2.txt"));
}


int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);

   if (RUN_ALL_TESTS() == 0) {
      std::cout << "All tests passed.\n";
   }

   init();
   return 0;
}
