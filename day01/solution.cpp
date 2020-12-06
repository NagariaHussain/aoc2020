#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <string>
#include "../file_utils.h"
#include "solution.h"

using namespace std;


void printVector(vector<long>& v) {
    for (auto const &n: v) {
        cout << n << " ";
    }
    cout << endl;
}

void init() {
    // vector<vector<long> > inp;
    // CHANGE THE DAY!
    // FileUtils::read_as_list_of_split_longs("day0/input.txt", inp, ',', '"', '#');
    vector<long> exp{};

    ifstream f{"day0/input.txt"};
    string buf;

    while (getline(f, buf)) {
        exp.push_back(stol(buf));
    }

    sort(exp.begin(), exp.end());

    int i =0;
    int j = exp.size() - 1;

    // PART I
    // while (i < j) {
    //     long n = exp[i] + exp[j];
    //     cout << n << endl;
    //     if (n == 2020) {
    //         cout << "ans: "<< exp[i] * exp[j] << "\n";
    //         break;

    //     }  else if (n < 2020) {
    //         i++;
    //     }   else {
    //         j--;
    //     }      
    // }

    for (i = 0; i < exp.size(); i++) {
        for (j = 0; j < exp.size(); j++) {
            for (int k = 0; k < exp.size(); k++) {
                if (i == j || j == k || i == k) {
                    continue;
                }

                long n = exp[i] + exp[j] + exp[k];

                if (n == 2020) {
                    cout << "AnS: " << exp[i] * exp[j] * exp[k];
                    return;
                }

            }
        }
    }

}

