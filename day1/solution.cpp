#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include "../file_utils.h"
#include "solution.h"

using namespace std;



bool isValid(std::string pass, char chr, int min, int max) {
    size_t l = pass.size();
    int count = 0;

    for (size_t i = 0; i < l; i++) {
        if (pass[i] == chr) {
            count++;
        }
    }

    if (count > max || count < min) {
        return false;
    }

    return true;
}


bool isValidPart2(std::string pass, char chr, int in1, int in2) {
    if (pass[in1 - 1] == chr) {
        if (pass[in2 - 1] == chr) {
            return false;
        }
        else {
            return true;
        }
    }

    if (pass[in2 - 1] == chr) {
        return true;
    }

}

void init() {
    // std::vector<std::vector<long> > inp;
    // CHANGE THE DAY!
    // FileUtils::read_as_list_of_split_longs("day1/input.txt", inp, ',', '"', '#');
    // cout << "From solution file\n";

    // vector<long> exp{};

    ifstream f{"day1/input.txt"};
    string buf;
    stringstream sbuf;

    int min, max;
    char dummy, c;
    string pass;
    int count = 0;

    while (getline(f, buf)) {
        sbuf << buf;
        sbuf >> min >> dummy >> max >> c >> dummy >> pass;
        // cout << pass << "\n";

        if (isValidPart2(pass, c, min, max)) {
            count++;
        }
        sbuf.clear();
    }

    cout << count << "\n";
    // while (getline(f, buf)) {
        // exp.push_back(stol(buf));
    // }
}

