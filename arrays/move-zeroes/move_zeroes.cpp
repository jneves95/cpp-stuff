#include <iostream>
#include <vector>

/**
 * Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 * The algorithm should be in-place.
 */

using namespace std;

// Naive approach: use a method similar to bubble sort, moving zeroes forward while swapping with non-zero values
void moveZeroesNaive(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ) {
        if (nums[i] == 0 && nums[i+1] != 0) {
            // Swap
            int temp = nums[i];
            nums[i] = nums[i+1];
            nums[i+1] = temp;

            // Iterate backwards if possible
            if (i != 0) i--; 
            else i++;
        }
        else i++;
    }
}

// Smart approach: since we either have zeroes and non-zero values, we can just iterate over the array and fill the array from the start with non-zero values,
// and then fill the rest of the array with zeroes.
void moveZeroes(vector<int>& nums) {
    for (int i = 0, j = 0; i < nums.size(); i++) {
        if (nums[i] != 0) nums[j++] = nums[i];
        if (i != j - 1) nums[i] = 0;
    }
}

int main() {
    vector<int> example = {0, 0, 1, 3, 12, 0, 6, 0, 7, 8};
    moveZeroes(example);

    for (int i : example) {
        cout << i << " ";
    }

    cout << endl;
}