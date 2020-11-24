#include <gtest/gtest.h>
#include "solution.h"


TEST(SUITE_NAME, TEST_NAME) {
   ASSERT_EQ(5, 5);
}


int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);

   if (RUN_ALL_TESTS() == 0) {
      std::cout << "All tests passed.\n";
   }

   init();
   return 0;
}
