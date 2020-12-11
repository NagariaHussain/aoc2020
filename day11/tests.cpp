#include <gtest/gtest.h>
#include "solution.h"
#include <fstream>

TEST(PART1, test_p1_example) {
   ASSERT_EQ(37, getPart1("day11/test1.txt"));
}


TEST(PART2, test_p2_example) {
   ASSERT_EQ(26, getPart2("day11/test1.txt"));
}


TEST(PART2, test_p2_example2) {
   ifstream f{"day11/test2.txt"};

   string buf;
   vector<string> inp;

   while(getline(f, buf)) {
      inp.push_back(buf);
   }

   ASSERT_TRUE(willOccupy2(inp, 3, 3));
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);

   if (RUN_ALL_TESTS() == 0) {
      std::cout << "All tests passed.\n";
   }

   init();
   return 0;
}
