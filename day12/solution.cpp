#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <math.h>
#include <unordered_set>
#include <algorithm>
#include "../file_utils.h"
#include "solution.h"

using namespace std;


pair<float, float> rotateVectorAnti(pair<float, float>& v, int angle) {
    float s = sin(angle * (M_PI / 180));
    float c = cos(angle * (M_PI / 180));

    float x = v.first;
    float y = v.second;

    pair<float, float> nv;

    nv.first  = x*c - y*s;
    nv.second = x*s + y*c;

    return nv;
}


pair<double, double> rotateVectorAnti(pair<double, double>& v, int angle) {
    double s = sin(angle * (M_PI / 180));
    double c = cos(angle * (M_PI / 180));

    double x = v.first;
    double y = v.second;

    pair<double, double> nv;

    nv.first  = x*c - y*s;
    nv.second = x*s + y*c;

    return nv;
}

pair<float, float> rotateVector(pair<float, float>& v, int angle) {
    float s = sin(angle * (M_PI / 180));
    float c = cos(angle * (M_PI / 180));

    float x = v.first;
    float y = v.second;

    pair<float, float> nv;

    nv.first  = x*c + y*s;
    nv.second = -x*s + y*c;

    return nv;
}


pair<double, double> rotateVector(pair<double, double>& v, int angle) {
    double s = sin(angle * (M_PI / 180));
    double c = cos(angle * (M_PI / 180));

    double x = v.first;
    double y = v.second;

    pair<double, double> nv;

    nv.first  = x*c + y*s;
    nv.second = -x*s + y*c;

    return nv;
}

double getPart1(string file) {
    ifstream f{file};
    string buf;
    pair<double, double> xy{0.0, 0.0};
    pair<float, float> vel_vec{1, 0};

    while (getline(f, buf)) {
        string c = buf.substr(0, 1);
        int val = stoi(buf.substr(1, buf.size() - 1));
        
        if (c == "N") xy.second-=val;
        else if (c == "S") xy.second+=val;
        else if (c == "E") xy.first+=val;
        else if (c == "W") xy.first-=val;
        else if (c == "F") 
        {   
            xy.first += vel_vec.first * val;
            xy.second += vel_vec.second * val;
        } 
        else if (c == "R") 
        {
            vel_vec = rotateVectorAnti(
                vel_vec,
                val
            );

        }
        else if (c == "L") 
        {
            vel_vec = rotateVector(
                vel_vec,
                val
            );
        }
    }

    return abs(xy.first) + abs(xy.second);
}


double getPart2(string file) {
    ifstream f{file};
    string buf;
    pair<double, double> xy_boat{0.0, 0.0};
    pair<double, double> xy_wp{10.0, -1.0};

    while (getline(f, buf)) {
        string c = buf.substr(0, 1);
        int val = stoi(buf.substr(1, buf.size() - 1));

        if (c == "N") xy_wp.second-=val;
        else if (c == "S") xy_wp.second+=val;
        else if (c == "E") xy_wp.first+=val;
        else if (c == "W") xy_wp.first-=val;
        else if (c == "F") 
        {   
            xy_boat.first  += (val * (xy_wp.first));
            xy_boat.second += (val * (xy_wp.second));
        } 
        else if (c == "R") 
        {
            pair<double, double> vec{xy_wp.first, xy_wp.second};
            vec = rotateVectorAnti(vec, val);
            xy_wp.first = vec.first;
            xy_wp.second = vec.second;
        }
        else if (c == "L") 
        {
            pair<double, double> vec{xy_wp.first, xy_wp.second};
            vec = rotateVector(vec, val);
            xy_wp.first = vec.first;
            xy_wp.second = vec.second;
        }
        // cout << buf << "\n";
        // cout << "current pos boat: " << xy_boat.first << ", " << xy_boat.second << "\n";
        // cout << "current pos wp: " << xy_wp.first << ", " << xy_wp.second << "\n";
    }


    return abs(xy_boat.first) + abs(xy_boat.second);
}

void init() {
    cout << "ans1: " << getPart1("day12/input.txt") << "\n";
    cout << "ans2: " << getPart2("day12/input.txt") << "\n";
}


/** To print a vector of longs */
void printVector(std::vector<long>& v) {
    for (auto const &n: v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
