#include <iostream>
#include <vector>
#include <map>

using namespace std;

class ThreeSumMult {
public:

    // First approach: recursive - O(n^3)
    int threeSumMultRecursive(vector<int>& arr, vector<int>::iterator pos, int target, int sum, int picked) {
        if (pos == arr.end()) return 0;
        
        int count = 0;

        if (picked == 2) {  // Stopping condition, we already have 2 elements of our 3-tuple, so the last element will need to be target-sum
            vector<int>::iterator it = pos;
            while (it != arr.end()) {
                if (*it == target - sum) count++;
                it++;
            }
        }
        else {  // To avoid repeating combinations, for every number we pick, we only consider other numbers that come after it in the array
            vector<int>::iterator it = pos;
            while (it != arr.end()) {
                count += threeSumMultRecursive(arr, it + 1, target, sum + *it, picked + 1);
                it++;
            }
        }

        return count;
    }

    // Second approach: map the number counts and then get the possible combinations from the key set, and calculate the multiplicities by using math
    // Complexity: O(N + M^2) where M = number of distinct numbers in our array
    int threeSumMultCounts(vector<int>& arr, int target) {
        long long total = 0;    // Use long long for every time we calculate counts to avoid undefined behavior of signed integer overflows
        int MOD = 1'000'000'007;

        // Map the counts
        map<int, int> counts;
        for (int i : arr) { 
            counts[i]++;
        }

        // To retrieve our keyset, use an iterator
        vector<int> keys;
        for (pair<int, int> p : counts) {
            keys.push_back(p.first);
        }

        // Now for every key X, we check if it's possible to reach our target with 3*X, then 2*X + Y, then X + Y + Z
        for (auto it = keys.begin(); it != keys.end(); it++) {
            int xVal = *it;
            long long xCount = counts[xVal];

            // 3 of the same
            if (xCount >= 3 && xVal * 3 == target) {
                // Combinations: sample of 3 from X
                total = (total + xCount * (xCount-1) * (xCount-2) / 6) % MOD;   // (why long long example: 3000*2999*2998 would overflow a signed integer)
            }

            // 2 of the same and another
            for (auto it2 = it + 1; it2 != keys.end(); it2++) {
                int yVal = *it2;
                long long yCount = counts[yVal];

                if (xCount >= 2 && xVal * 2 + yVal == target) {    // 2X + Y - combinations: sample of 2 from X
                    total = (total + (xCount * (xCount-1) / 2) * yCount) % MOD;
                }
                else if (yCount >= 2 && xVal + yVal * 2 == target) {   // X + 2Y - combinations: sample of 2 from Y
                    total = (total + (yCount * (yCount-1) / 2) * xCount) % MOD;
                }
                
                // All different
                int zVal = target - xVal - yVal;
                map<int, int>::iterator it3 = counts.find(zVal);
                if (it3 != counts.end() && yVal < zVal) {
                    long long zCount = counts[zVal];
                    total = (total + xCount * yCount * zCount) % MOD;
                }
            }
        }

        return (int) total;
    }

    // For this approach, we map the count of sums of two distinct numbers up to (not including) our current number - and so for every new number, 
    // we know how many ways to use two different numbers before it so that by summing all 3 we get our target. This method avoids repeating combinations.
    int threeSumMultSmart(vector<int>& arr, int target) {
        map<int, int> map;
        int count = 0;
        const int MOD = 1000000007; // Used to keep value from overflowing

        for (auto i = arr.begin(); i != arr.end(); i++) {
            count = (count + map[target - *i]) % MOD;

            for (auto j = arr.begin(); j != i; j++) {
                map[*i + *j]++;
            }
        }

        return count;
    }
};

int main() {
    ThreeSumMult tsm;
    vector<int> arr1 = {1, 1, 2, 2, 2, 2};
    vector<int> arr2 = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};

    cout << "Using recursive algorithm:" << endl;
    cout << tsm.threeSumMultRecursive(arr1, arr1.begin(), 5, 0, 0) << endl;
    cout << tsm.threeSumMultRecursive(arr2, arr2.begin(), 8, 0, 0) << endl;
    cout << endl;

    cout << "Using look-back algorithm:" << endl;
    cout << tsm.threeSumMultSmart(arr1, 5) << endl;
    cout << tsm.threeSumMultSmart(arr2, 8) << endl;
    cout << endl;

    cout << "Using mapped counts algorithm:" << endl;
    cout << tsm.threeSumMultCounts(arr1, 5) << endl;
    cout << tsm.threeSumMultCounts(arr2, 8) << endl;
    cout << endl;
}