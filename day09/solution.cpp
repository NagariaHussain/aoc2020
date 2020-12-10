#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <deque>
#include <unordered_set>
#include <algorithm>
#include "../file_utils.h"
#include "solution.h"

using namespace std;


bool isSum(deque<long> queue, long target) {
    sort(queue.begin(), queue.end());

    int i = 0, j = queue.size() - 1;

    while (i < j) {
        long a = queue[i];
        long b = queue[j];

        if ((a + b) == target) {
            return true;
        } else if ((a + b) < target) {
            ++i;
        } else {
            --j;
        }
    }

    return false;
}

long anomalyNum(string file, long pre_size) {
    deque<long> exp{};

    ifstream f{file};
    string buf;

    while (getline(f, buf)) {
        long num = stol(buf);
        if (exp.size() == (pre_size)) {

            if (!isSum(exp, num)) {
                return num;
            }
            exp.pop_front();
        }

        exp.push_back(num);
    }

    return -1;
}


pair<bool, size_t> checkSum(const vector<long>& v, long target, size_t size) {
    for (size_t i = 0; i < v.size() - (size - 1); i++) {
        long sum = 0;
    
        for (size_t j = i; j < (i + size); j++) {
            sum += v[j];
        }

        if (sum == target) {
            return pair<bool, size_t>{true, i}; 
        }
    }

    return pair<bool, size_t>{false, 0};
}

long long findContiguous(string file, long pre_size) {
    ifstream f{file};
    string buf;
    vector<long> inp;

    long anomaly = anomalyNum(file, pre_size);

    while (getline(f, buf)) {
        inp.push_back(stol(buf));
    }

    size_t max_size = 0;
    size_t location_max = 0;

    for (size_t i = 2; i <= inp.size(); i++) {
        pair<bool, size_t> location = checkSum(inp, anomaly, i);
        if (location.first) {
            if (i > max_size) {
                max_size = i;
                location_max = location.second;
                cout << "max_size: " << max_size << " with location: " << location_max << "\n";
            }
        }
    }

    long max = inp[location_max];
    long min = inp[location_max];



    for (size_t i = location_max; i < (location_max + max_size); i++) {
        if (inp[i] > max) {
            max = inp[i];
        }

        if (inp[i] < min) {
            min = inp[i];
        }
    }
    cout << "max: " << max << ", min: " << min << "\n";
    return (max + min);
}
void init() {
    cout << "From solution file\n";
    cout << "ans:" << findContiguous("day09/input.txt", 25) << "\n";
}


/** To print a vector of longs */
void printVector(std::vector<long>& v) {
    for (auto const &n: v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
