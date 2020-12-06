#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <set>
#include "../file_utils.h"
#include "solution.h"

using namespace std;

/* PART 1 */
bool isValid(unordered_set<string> pp) {
    unordered_set<string> valids {
        "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"
    };

    for (auto v: valids) {
        if (pp.count(v) == 0) {
            return false;
        }
    }

    return true;
}

/* PART 2 */
bool isValid2(map<string, string> pp) {
    unordered_set<string> valids {
        "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"
    };


    for (auto v: valids) {
        if (pp.count(v) == 0) {
            cout << "FAILED AT: " << v << " Does not exist\n";
            return false;
        }

        if (v == "byr") {
            int b_year = stoi(pp[v]);

            if (b_year > 2002 || b_year < 1920) {
                cout << "FAILED AT: " << v  << "," << pp[v] << " Not b/w 2002 and 1920\n";
                return false;
            }
        }

        if (v == "iyr") {
            int b_year = stoi(pp[v]);

            if (b_year > 2020 || b_year < 2010) {
                cout << "FAILED AT: " << v  << "," << pp[v] << " Not b/w 2020 and 2010\n";
                return false;
            }
        }

        if (v == "eyr") {
            int b_year = stoi(pp[v]);

            if (b_year > 2030 || b_year < 2020) {
                cout << "FAILED AT: " << v  << "," << pp[v] << " Not b/w 2030 and 2020\n";
                return false;
            }
        }

        if (v == "hgt") {
            string unit = pp[v].substr(pp[v].size() - 2, 2);
            
            if (unit == "cm" ) {
                int h = stoi(pp[v].substr(0, pp[v].size() - 2));

                if (h < 150 || h > 193) {
                    cout << "FAILED AT: " << v  << "," << pp[v] << " Not b/w 150 and 193\n";
                    return false;
                }

            } else if (unit == "in") {
                int h = stoi(pp[v].substr(0, pp[v].size() - 2));

                if (h < 59 || h > 76) {
                    cout << "FAILED AT: " << v  << "," << pp[v] << " Not b/w 59 and 76\n";
                    return false;
                }
            } 
            else {
                cout << "FAILED AT: " << v  << "," << pp[v] << " Not with unit\n";
                return false;
            }
        }

        if (v == "hcl") {
            if (pp[v].size() != 7 || pp[v][0] != '#')  {
                cout << "FAILED AT: " << v  << "," << pp[v] << " Not # or not len 7\n";
                return false;
            }

            string color = pp[v].substr(1, 6);

            for (char c: color) {
                if (!((c >= 'a' && c <= 'f') || (c >= '0' && c <= '9'))) {
                    cout << "FAILED AT: " << v  << "," << pp[v] << " Not a valid hex color\n";
                    return false;
                }
            }
        }

        if (v == "ecl") {
            unordered_set<string> s{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

            if (s.count(pp[v]) == 0) {
                cout << "FAILED AT: " << v  << "," << pp[v] << " Not in amb, blu, ...\n";
                return false;
            }
        }

        if (v == "pid") {
            if (pp[v].size() != 9) {
                cout << "FAILED AT: " << v  << ",*" << pp[v] << "* pid not size 9!\n";
                return false;
            }

            try {
                int num = stoi(pp[v]);
            } catch (const exception& e) {
                cout << "pid not a number\n";
                return false;
            }
        }
    
    }

    return true;
}

void init() {
    // std::vector<std::vector<long> > inp;
    // // CHANGE THE DAY!
    // FileUtils::read_as_list_of_split_longs("day0/input.txt", inp, ',', '"', '#');
    // cout << "From solution file\n";

    ifstream f{"day3/input.txt"};
    string buf = "something";

    map<string, string> cred;

    vector<string> passports{};
    string current_pass = "";

    while(getline(f, buf)) {
        if (buf == "") {
            passports.push_back(current_pass);
            current_pass = "";
        } else {
            if (current_pass != "") {
                current_pass += (" " + buf);
            } else {
                current_pass += buf;
            }
        }   
    }

    if (current_pass != "") {
        passports.push_back(current_pass);
    }

    int valid_pass = 0;

    for (auto& s : passports) {
        vector<string> vec = FileUtils::split_line_to_strings(s, ' ', '!', '!');
        for (auto v: vec) {
            vector<string> dec = FileUtils::split_line_to_strings(v, ':', '!', '!');
            cred[dec[0]] = dec[1];
        }

        if(isValid2(cred)) {
            valid_pass++;
        }

        cred.clear();
    }


    cout << "ans: "<< valid_pass;
}


/** To  */
void printVector(std::vector<long>& v) {
    for (auto const &n: v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
