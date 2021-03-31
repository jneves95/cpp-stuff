#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isMatch(string& stamp, string& target, int fromIndex) {
    bool oneMatch = false;
    string::iterator s, t;

    for (s = stamp.begin(), t = target.begin() + fromIndex; s != stamp.end() && t != target.end(); s++, t++) {
        if (*s == *t) oneMatch = true;
        else if(*t != '?') return false;
    }

    return oneMatch;
}

vector<int> movesToStamp(string stamp, string target) {
    int lenStamp = stamp.length();
    int lenTarget = target.length();
    vector<int> ans;

    int i = 0;  // Our iterator

    while (i <= lenTarget - lenStamp) {
        // Check for matches
        if (isMatch(stamp, target, i)) {
            // Fill with '?'
            for (int j = i; j < i + lenStamp; j++) {
                target[j] = '?';
            }
            ans.push_back(i);
            i = 0;  // Restart
        }
        else {
            i++;
        }
    }

    // Check if the string was a valid succession of stamps, otherwise return empty array
    for (auto it = target.begin(); it != target.end(); it++) {
        if (*it != '?') return {};
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string target = "aabbaabbbab";
    string stamp = "ab";

    vector<int> result = movesToStamp(stamp, target);

    for (int i : result) {
        cout << i << " ";
    }
}