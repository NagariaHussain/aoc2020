#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <unordered_set>
#include <algorithm>
#include "../file_utils.h"
#include "solution.h"

using namespace std;


bool areIndexValid(const vector<string>& arrangements, size_t x, size_t y) {
    const size_t max_row = arrangements.size() - 1;
    const size_t max_col = arrangements[0].size() - 1;

    return (x >= 0) && (y >= 0) && (x <= max_row) && (y <= max_col);
}


bool isDiagonalOccupied(
    const vector<string>& arrangements, 
    size_t x, 
    size_t y, 
    pair<int, int> diag_type
) {
    int dx = diag_type.first;
    int dy = diag_type.second;

    x += dx; y += dy;
    while(areIndexValid(arrangements, x, y)) {
        if (arrangements[x][y] == 'L') {
            return false;
        }
        if (arrangements[x][y] == '#') {
            return true;
        }
        x += dx; y += dy;
    }

    return false;
}

bool willOccupy(const vector<string>& arrangements, size_t row, size_t col) {
    bool willIt = true;
    if (arrangements[row][col] == 'L') {
        size_t x;
        size_t y;

        // Down
        x = row + 1; y = col;
        if (areIndexValid(arrangements, x, y)) {
            willIt = willIt && (arrangements[x][y] != '#');
        } 

        // Up
        x = row - 1; y = col;
        if (areIndexValid(arrangements, x, y)) {
            willIt = willIt && (arrangements[x][y] != '#');
        }

        // Right
        x = row; y = col + 1;
        if (areIndexValid(arrangements, x, y)) {
            willIt = willIt && (arrangements[x][y] != '#');
        }

        // Left
        x = row; y = col - 1; 
        if (areIndexValid(arrangements, x, y)) {
            willIt = willIt && (arrangements[x][y] != '#');
        }

        // Diagonal down-right
        x = row + 1; y = col + 1;
        if (areIndexValid(arrangements, x, y)) {
            willIt = willIt && (arrangements[x][y] != '#');
        }

        // Diagonal down-left
        x = row + 1; y = col - 1;
        if (areIndexValid(arrangements, x, y)) {
            willIt = willIt && (arrangements[x][y] != '#');
        }

        // Diagonal up-right
        x = row - 1; y = col + 1;
        if (areIndexValid(arrangements, x, y)) {
            willIt = willIt && (arrangements[x][y] != '#');
        }

        // Diagonal up-left
        x = row - 1; y = col - 1;
        if (areIndexValid(arrangements, x, y)) {
            willIt = willIt && (arrangements[x][y] != '#');
        }

        return willIt;
    }

    return false;
}

bool willEmpty(const vector<string>& arrangements, size_t row, size_t col) {
    int count = 0;
    // cout << "willEmpty: " << row << ", " << col << "\n";
    if (arrangements[row][col] == '#') {
        size_t x;
        size_t y;

        // Down
        x = row + 1; y = col;
        if (areIndexValid(arrangements, x, y)) {
            if (arrangements[x][y] == '#') {
                count++;
            }
        } 

        // Up
        x = row - 1; y = col;
        if (areIndexValid(arrangements, x, y)) {
            if (arrangements[x][y] == '#') {
                count++;
            }
        }

        // Right
        x = row; y = col + 1;
        if (areIndexValid(arrangements, x, y)) {
            if (arrangements[x][y] == '#') {
                count++;
            }
        }

        // Left
        x = row; y = col - 1; 
        if (areIndexValid(arrangements, x, y)) {
            if (arrangements[x][y] == '#') {
                count++;
            }
        }

        // Diagonal down-right
        x = row + 1; y = col + 1;
        if (areIndexValid(arrangements, x, y)) {
            if (arrangements[x][y] == '#') {
                count++;
            }
        }

        // Diagonal down-left
        x = row + 1; y = col - 1;
        if (areIndexValid(arrangements, x, y)) {
            if (arrangements[x][y] == '#') {
                count++;
            }
        }

        // Diagonal up-right
        x = row - 1; y = col + 1;
        if (areIndexValid(arrangements, x, y)) {
            if (arrangements[x][y] == '#') {
                count++;
            }
        }

        // Diagonal up-left
        x = row - 1; y = col - 1;
        if (areIndexValid(arrangements, x, y)) {
            if (arrangements[x][y] == '#') {
                count++;
            }
        }
        return count >= 4;
    }

    return false;
}

bool willOccupy2(const vector<string>& arrangements, size_t row, size_t col) {
    bool willIt = true;
    if (arrangements[row][col] == 'L') {
        pair<int, int>xy{};
        size_t x = row;
        size_t y = col;

        // Down
        xy.first = 1; xy.second = 0;
        willIt = willIt && !isDiagonalOccupied(arrangements, x, y, xy);


        // Up
        xy.first = -1; xy.second = 0;
        willIt = willIt && !isDiagonalOccupied(arrangements, x, y, xy);

        // Right
        xy.first = 0; xy.second = 1;
        willIt = willIt && !isDiagonalOccupied(arrangements, x, y, xy);

        // Left
        xy.first = 0; xy.second = -1;
        willIt = willIt && !isDiagonalOccupied(arrangements, x, y, xy);


        // Diagonal down-right
        xy.first = 1; xy.second = 1;
        willIt = willIt && !isDiagonalOccupied(arrangements, x, y, xy);
      

        // Diagonal down-left
        xy.first = 1; xy.second = -1;
        willIt = willIt && !isDiagonalOccupied(arrangements, x, y, xy);
   

        // Diagonal up-right
        xy.first = -1; xy.second = 1;
        willIt = willIt && !isDiagonalOccupied(arrangements, x, y, xy);
  

        // Diagonal up-left
        xy.first = -1; xy.second = -1;
        willIt = willIt && !isDiagonalOccupied(arrangements, x, y, xy);
  
        return willIt;
    }

    return false;
}


bool willEmpty2(const vector<string>& arrangements, size_t row, size_t col) {
    int count = 0;

    if (arrangements[row][col] == '#') {
        pair<int, int>xy{};
        size_t x = row;
        size_t y = col;

        // Down
        xy.first = 1; xy.second = 0;
        if(isDiagonalOccupied(arrangements, x, y, xy)) ++count;


        // Up
        xy.first = -1; xy.second = 0;
        if(isDiagonalOccupied(arrangements, x, y, xy)) ++count;

        // Right
        xy.first = 0; xy.second = 1;
        if(isDiagonalOccupied(arrangements, x, y, xy)) ++count;

        // Left
        xy.first = 0; xy.second = -1;
        if(isDiagonalOccupied(arrangements, x, y, xy)) ++count;


        // Diagonal down-right
        xy.first = 1; xy.second = 1;
        if(isDiagonalOccupied(arrangements, x, y, xy)) ++count;
      

        // Diagonal down-left
        xy.first = 1; xy.second = -1;
        if(isDiagonalOccupied(arrangements, x, y, xy)) ++count;

        // Diagonal up-right
        xy.first = -1; xy.second = 1;
        if(isDiagonalOccupied(arrangements, x, y, xy)) ++count;
  

        // Diagonal up-left
        xy.first = -1; xy.second = -1;
        if(isDiagonalOccupied(arrangements, x, y, xy)) ++count;

        return count >= 5;
    }

    return false;
}

bool stateMatch(const vector<string>& v1, const vector<string>& v2) {
    for (size_t i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }

    return true;    
}

long long getPart1(string file) {
    vector<string> prev{};
    vector<string> new_state{};

    ifstream f{file};
    string buf;

    while (getline(f, buf)) {
        prev.push_back(buf);
        new_state.push_back(buf);
    }

    bool stable = false;

    while(!stable) {
        // cout << "run: " << run << "\n";
        for (size_t i = 0; i < prev.size(); ++i)
        {
            for (size_t j = 0; j < prev[0].size(); ++j) {
                // cout << "i, j = " << i << ", " << j << "\n";
                if (willEmpty(prev, i, j)) {
                    new_state[i][j] = 'L';
                } 
                
                if (willOccupy(prev, i, j)) {
                    new_state[i][j] = '#';
                }
            }
        }

        if (stateMatch(new_state, prev)) {
            stable = true;
        } else {
            for (size_t k = 0; k < prev.size(); k++) {
                prev[k] = new_state[k];
            }
        }

    }

    long long ans = 0;

    for (auto s: new_state) {
        for (auto c: s) {
            if (c == '#') {
                ans++;
            }
        }
    }

    return ans;
}



long long getPart2(string file) {
    vector<string> prev{};
    vector<string> new_state{};

    ifstream f{file};
    string buf;

    while (getline(f, buf)) {
        prev.push_back(buf);
        new_state.push_back(buf);
    }

    bool stable = false;

    while(!stable) {
        // cout << "run: " << run << "\n";
        for (size_t i = 0; i < prev.size(); ++i)
        {
            for (size_t j = 0; j < prev[0].size(); ++j) {
                // cout << "i, j = " << i << ", " << j << "\n";
                if (willEmpty2(prev, i, j)) {
                    new_state[i][j] = 'L';
                } 
                
                if (willOccupy2(prev, i, j)) {
                    new_state[i][j] = '#';
                }
            }
        }

        if (stateMatch(new_state, prev)) {
            stable = true;
        } else {
            for (size_t k = 0; k < prev.size(); k++) {
                prev[k] = new_state[k];
                cout << new_state[k] << "\n";
            }
            cout << "\n\n";
        }

    }

    long long ans = 0;

    for (auto s: new_state) {
        for (auto c: s) {
            if (c == '#') {
                ans++;
            }
        }
    }

    return ans;
}



void init() {
    cout << "ans1: " << getPart1("day11/input.txt") << "\n";
    cout << "ans2: " << getPart2("day11/input.txt") << "\n";
}


/** To print a vector of longs */
void printVector(std::vector<long>& v) {
    for (auto const &n: v) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
