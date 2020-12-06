#include <gtest/gtest.h>
#include "solution.h"
#include <map>

using namespace std;

TEST(part2, part2Valid) {
   map<string, string> valid_pass;

   ASSERT_FALSE(isValid2(valid_pass));
   
   valid_pass["pid"] = "087499704";
   valid_pass["hgt"] = "74in";
   valid_pass["ecl"] = "grn";
   valid_pass["iyr"] = "2012";
   valid_pass["eyr"] = "2030";
   valid_pass["byr"] = "1980";
   valid_pass["hcl"] = "#623a2f";

   ASSERT_TRUE(isValid2(valid_pass));
}


TEST(part2, part2InValid) {
   map<string, string> invalid_pass;
   invalid_pass["eyr"] = "1972";
   invalid_pass["cid"] = "100";
   invalid_pass["hcl"] = "#18171d";
   invalid_pass["ecl"] = "amb";
   invalid_pass["hgt"] = "170";
   invalid_pass["pid"] = "186cm";
   invalid_pass["iyr"] = "2018";
   invalid_pass["byr"] = "1926";

   ASSERT_FALSE(isValid2(invalid_pass));
}

int main(int argc, char **argv) {
   testing::InitGoogleTest(&argc, argv);

   if (RUN_ALL_TESTS() == 0) {
      std::cout << "All tests passed.\n";
   }

   init();
   return 0;
}
