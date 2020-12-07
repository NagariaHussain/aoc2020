#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <unordered_set>
#include <algorithm>
#include "../file_utils.h"
#include "solution.h"

using namespace std;

// Read file and generate data structure
map<string, map<string, int>> getBagTree(string file) {
    vector<string> inp_tokens;
    ifstream f{file};
    string buf;

    map<string, map<string, int>> bagTree;

    while (getline(f, buf)) {
        inp_tokens = FileUtils::split_line_to_strings(buf, ' ', '!', '!');

        string outer_bag = inp_tokens[0] + inp_tokens[1];
        map<string, int> inner_bags{};

        for (int i = 4; i < inp_tokens.size() - 3; i += 4) {
            if (inp_tokens[i] == "no") {
                break;
            }
            inner_bags[inp_tokens[i + 1] + inp_tokens[i + 2]] = stoi(inp_tokens[i]);
            
        }

        bagTree[outer_bag] = inner_bags;
    }

    return bagTree;
}

bool recBags(
    string curr, 
    unordered_set<string>& ans_list, 
    map<string, map<string, int>>& bt, 
    string target
) {
    bool condition = false;
    bool has_child = false;

    if (curr == target) {
        return true;
    }

    for (auto& m: bt[curr]) {
        has_child = true;
        unordered_set<string> short_set{m.first};
        bool res = recBags(m.first, short_set, bt, target);
        if (res) {
            for (auto& item: short_set) {
                ans_list.insert(item);
            }
            condition = true;
        }
    }

    if (has_child) {
        return condition;
    }

    return false;
}

int countBags1(string file) {
    unordered_set<string> answers;
    
    map<string, map<string, int>> bagTree = getBagTree(file);

    for (auto& pr: bagTree) {
        if(recBags(pr.first, answers, bagTree, "shinygold")) {
            answers.insert(pr.first);
        }
    }

    answers.erase("shinygold");

    return answers.size();
}


long countRec(string b_name, map<string, map<string, int>>& bt) {
    long count = 1;

    if (bt.count(b_name) > 0) {
        for (auto& m: bt[b_name]) {
            count += m.second * countRec(m.first, bt);
        }
    }

    return count;
}

int countBags2(string file) {

    map<string, map<string, int>> bagTree = getBagTree(file);

    long ans = 0;

    for (auto& bag: bagTree["shinygold"]) {
        string b_name = bag.first;
        int b_count = bag.second;

        ans += (b_count * countRec(b_name, bagTree));

    }

    return ans;
}

void init() {
    cout << "ans: " << countBags1("day07/input.txt") << "\n";
    cout << "ans: " << countBags2("day07/input.txt") << "\n";
}


/** To  */
void printVector(std::vector<long>& v) {
    for (auto const &n: v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
