#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <unordered_set>
#include <algorithm>
#include "../file_utils.h"
#include "solution.h"

using namespace std;

long getAccum1(string file) {
    long acc = 0;
    vector<pair<string, long>> lines;
    ifstream f{file};
    string buf;

    while (getline(f, buf)) {
        string ins = buf.substr(0, 3);
        long param = stol(buf.substr(4, buf.size() - 4));
        // cout << param << "\n";
        lines.push_back(pair<string, long>{ins, param});
    }

    int current_ins = 0;

    unordered_set<int> executed;

    while (current_ins < lines.size())
    {
        executed.insert(current_ins);

        auto cur = lines[current_ins];
        string ins_type = cur.first;
        long ins_param = cur.second;

        if (ins_type == "nop") {
            current_ins++;
        } else if (ins_type == "acc") {
            acc += ins_param;
            current_ins++;
        } else {
            current_ins += ins_param;
        }

        if (executed.count(current_ins) > 0) {
            break;
        }
    }

    return acc;
}


long getAccum2(string file) {

    vector<pair<string, long>> lines;
    ifstream f{file};
    string buf;

    while (getline(f, buf)) {
        string ins = buf.substr(0, 3);
        long param = stol(buf.substr(4, buf.size() - 4));
        lines.push_back(pair<string, long>{ins, param});
    }

    bool fixed = false;
    long acc = 0;

    vector<int> fnop, fjmp;
    int cnop, cjmp;

    for (size_t i = 0; i < lines.size(); i++) {
        if (lines[i].first == "jmp") {
            fjmp.push_back(i);
        }

        if (lines[i].first == "nop") {
            fnop.push_back(i);
        }
    }

    cnop = 0;
    cjmp = 0;

    cout << "fnop size:  " << fnop.size() << "\n";
    cout << "fjmp size:  " << fjmp.size() << "\n";

    bool swapJmp = true;

    while (!fixed) {
        int current_ins = 0;
        acc = 0;
        unordered_set<int> executed;

        if (swapJmp) {
            lines[fjmp[cjmp]].first = "nop";
        } else {
            lines[fnop[cnop]].first = "jmp";
        }


        while (current_ins < lines.size())
        {
            executed.insert(current_ins);

            auto cur = lines[current_ins];
            string ins_type = cur.first;
            long ins_param = cur.second;

            if (ins_type == "nop") {
                current_ins++;
            } else if (ins_type == "acc") {
                acc += ins_param;
                current_ins++;
            } else {
                current_ins += ins_param;
            }

            if (executed.count(current_ins) > 0) {
                break;
            }
        }

        if (current_ins == lines.size()) {
            cout << "FIXED.\n"; 
            fixed = true;
        }

        if (swapJmp) {
            lines[fjmp[cjmp]].first = "jmp";
            cjmp++;
        } else {
            lines[fnop[cnop]].first = "nop";
            cnop++;
        }

        if (cjmp == fjmp.size()) {
            swapJmp = !swapJmp;
        }
        cout << cnop << ", " << cjmp << "\n";
    }

    return acc;
}


void init() {
    // std::vector<std::vector<long> > inp;
    // // CHANGE THE DAY!
    // FileUtils::read_as_list_of_split_longs("day0/input.txt", inp, ',', '"', '#');
    cout << "From solution file\n";

    // vector<long> exp{};

   cout << getAccum1("day08/input.txt") << "\n"; 
   cout << getAccum2("day08/input.txt") << "\n"; 
}


/** To print a vector of longs */
void printVector(std::vector<long>& v) {
    for (auto const &n: v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
