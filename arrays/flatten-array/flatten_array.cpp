#include <iostream>
#include <vector>
#include <stack>

#include "flatten_array.h"
#include "nested_integer.h"

using namespace std;

vector<int> flat(NestedInteger nestedInteger) {
    vector<int> ans;

    if (nestedInteger.isInteger()) {
        cout << nestedInteger.getInteger();
        ans.push_back(nestedInteger.getInteger());
        return ans;
    }
    else {
        cout << "[";
        vector<NestedInteger> arr = nestedInteger.getArray();
        for (auto it = arr.begin(); it != arr.end(); it++) {
            vector<int> temp = flat(*it);
            for (int i : temp) {
                ans.push_back(i);
            }
            if (it + 1 != arr.end()) {
                if (it->isInteger() && (it + 1)->isInteger()) cout << ",";
                cout << " ";
            } 
        }
        cout << "]";
    }

    return ans;
}


