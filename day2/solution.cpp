#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include "../file_utils.h"
#include "solution.h"

using namespace std;

int countTrees(vector<string>& inp, int right, int down) {
    int i = 0, j = 0,count = 0;
    while (i < inp.size() - down) {
        j += right;
        j = j % inp[i].size();
        i += down;

        if (inp[i][j] == '#') {
            count++;
        } 
    }
    cout << count << endl;
    return count;
}
void init() {
    std::vector<std::string> inp;
    // CHANGE THE DAY!
    FileUtils::read_as_list_of_strings("day2/input.txt", inp);

    // for (string s: inp) {
    //     cout << s << "\n";
    // }

    long mult = 1;
    vector<vector<int> > slopes(5);

    slopes[0] = vector<int>{1, 1};
    slopes[1] = vector<int>{3, 1};
    slopes[2] = vector<int>{5, 1};
    slopes[3] = vector<int>{7, 1};
    slopes[4] = vector<int>{1, 2};

    for (auto slope: slopes) {
        mult *= countTrees(inp, slope[0], slope[1]);
    }
    
    cout << "ans: " << mult << "\n";
}



void printVector(std::vector<long>& v) {
    for (auto const &n: v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

