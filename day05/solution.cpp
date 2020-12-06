#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include "../file_utils.h"
#include "solution.h"

using namespace std;

long getID(string bp) {

    int r, c;
    int max_r = 127, min_r = 0;
    int max_c = 7, min_c = 0;

    for (int i = 0; i < bp.size(); i++) {
        if (bp[i] == 'F') {
            int mid_r = min_r + ((max_r - min_r) / 2);
            max_r = mid_r - 1;
        } else if (bp[i] == 'B') {
            int mid_r = min_r + ((max_r - min_r) / 2);
            min_r = mid_r + 1;
        } else if (bp[i] == 'L') {
            int mid_c = min_c + ((max_c - min_c) / 2);
            max_c = mid_c - 1;
        } else {
            int mid_c = min_c + ((max_c - min_c) / 2);
            min_c = mid_c + 1;
        }
    }

    if (max_r > min_r) {
        r = max_r;
    } else {
        r = min_r;
    }

    if (min_c > max_c) {
        c = min_c;
    } else {
        c = max_c;
    }

    return ((r * 8) + c);
}

void init() {
    cout << "From solution file\n";
    vector<long> exp{};

    ifstream f{"day4/input.txt"};
    string buf;

    long cur_max = -INT32_MIN, cur_id;

    long id_sum = 0;

    while (getline(f, buf)) {
        cur_id = getID(buf);
        
        exp.push_back(cur_id);

        if (cur_id > cur_max) {
            cur_max = cur_id;
        }
    }

    exp.push_back(1);
    exp.push_back(-1);

    sort(exp.begin(), exp.end());

    int i = 2;
    int j = exp.size() - 1;

    while (i < (j - 1)) {
        if (exp[i] != (exp[i+1] - 1)) {
            cout << exp[i] << "!!" << exp[i+1] << "\n";
            break;
        }

        i++;
    }

    cout << "ans: " << cur_max;
}


/** To  */
void printVector(std::vector<long>& v) {
    for (auto const &n: v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
