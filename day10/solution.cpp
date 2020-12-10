#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <unordered_set>
#include <algorithm>
#include "../file_utils.h"
#include "solution.h"

using namespace std;

long getPart1(string file) {
    vector<long> exp{};

    ifstream f{file};
    string buf;

    exp.push_back(0);

    while (getline(f, buf)) {
        exp.push_back(stol(buf));
    }

    sort(exp.begin(), exp.end());

    long builtInJolt = exp[exp.size() - 1] + 3;
    
    std::cout << "built-in: " << builtInJolt << "\n";

    int diff1 = 0, diff3 = 0;

    for (size_t i = 0; i < exp.size() - 1; i++) {
        long diff = exp[i+1] - exp[i]; 
        if (diff == 1) {
            diff1++;
        } else if (diff == 3) {
            diff3++;
        }
    }

    ++diff3;

    return diff1 * diff3;
}


long long recNumArrangements(long n, long leaf, unordered_set<long>& adapters, unordered_set<long>& visited, long long mem[]) {
    if (n == leaf) {
        return 1;
    } 

    if (adapters.count(n) == 0) {
        return 0;
    }


    if (visited.count(n) > 0) {
        return mem[n];
    }
    
    visited.insert(n);
    long long ans = recNumArrangements(n+1, leaf, adapters, visited, mem) 
                    + recNumArrangements(n+2, leaf, adapters, visited, mem) 
                    + recNumArrangements(n+3, leaf, adapters, visited, mem);
    
    mem[n] = ans;
    return ans;
}

long long getPart2(string file) {
    vector<long> exp{};

    ifstream f{file};
    string buf;

    exp.push_back(0);

    while (getline(f, buf)) {
        exp.push_back(stol(buf));
    }

    sort(exp.begin(), exp.end());

    long leaf = exp[exp.size() - 1];
    long builtInJolt = leaf + 3;

    unordered_set<long> adapters{};
    unordered_set<long> visited{};
    long long memory[200];


    for (auto num: exp) {
        adapters.insert(num);
    }

    return recNumArrangements(0, leaf, adapters, visited, memory);
}
void init() {  
    std::cout << "ans1: " << getPart1("day10/input.txt") << "\n";  
    std::cout << "ans2: " << getPart2("day10/input.txt") << "\n";  
}


/** To print a vector of longs */
void printVector(std::vector<long>& v) {
    for (auto const &n: v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
