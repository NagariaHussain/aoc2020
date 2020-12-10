
#pragma once
#include <vector>
#include <map>

using namespace std;

void init();
void printVector(std::vector<long>& v);
long anomalyNum(string file, long pre_size);
long long findContiguous(string file, long pre_size);
pair<bool, size_t> checkSum(const vector<long>& v, long target, size_t size);