#pragma once

#include <vector>

using namespace std;

class NestedInteger {
private:
    int val;
    bool isInt = false;
    vector<NestedInteger> array;
public:
    NestedInteger(int val) : val(val), isInt(true) {}
    NestedInteger(vector<NestedInteger>& vec) : val(0), array(vec) {}
    NestedInteger(vector<int> vec) {
        val = 0;
        vector<NestedInteger> nestedArray;
        for (auto it = vec.begin(); it != vec.end(); it++) {
            nestedArray.push_back(NestedInteger(*it));
        }
        array = nestedArray;
    }

    bool isInteger() { return isInt; }

    int getInteger() { return val; }

    vector<NestedInteger> getArray() { return array; }
};