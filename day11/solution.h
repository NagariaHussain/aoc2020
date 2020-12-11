
#pragma once
#include <vector>
#include <map>

using namespace std;

void init();
void printVector(std::vector<long>& v);
long long getPart1(string file);
long long getPart2(string file);
bool willOccupy2(const vector<string>& arrangements, size_t row, size_t col);