#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <unordered_set>
#include <algorithm>
#include "../file_utils.h"
#include "solution.h"

using namespace std;

int countPart1(string file) {
    ifstream f{file};
    string buf;
    int sum = 0;

    unordered_set<char> cur_group;

    while (getline(f, buf)) {
        /* Group change */
        if (buf == "") {
            sum += cur_group.size();
            cur_group.clear();
        } else {
            for (auto c: buf) {
                cur_group.insert(c);
            }
        }
    }

    sum += cur_group.size();

    return sum;
}


int countPart2(string file) {
    ifstream f{file};
    string buf;
    int sum = 0;
    bool first_person = true;

    unordered_set<char> cur_group;
    unordered_set<char> new_group;
    

    while (getline(f, buf)) {
        /* Group change */
        if (buf == "") {
            sum += cur_group.size();
            cur_group.clear();
            first_person = true;
        } else {
            if (first_person) {
                for (auto c: buf) {
                    cur_group.insert(c);
                }
                first_person = false;
            } else {
                new_group.clear();

                for (auto c: buf) {
                    if (cur_group.count(c) > 0) {
                        new_group.insert(c);
                    }
                }

                cur_group = new_group;
            }
        }
    }
    sum += cur_group.size();

    return sum;
}


void init() {
    /* Part 1 */
    cout << "P1 ans:" << countPart1("day5/input.txt") << "\n";
    /* Part 2 */
    cout << "P2 ans:" << countPart2("day5/input.txt");
}

/** To  print the vector */
void printVector(std::vector<long>& v) {
    for (auto const &n: v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
