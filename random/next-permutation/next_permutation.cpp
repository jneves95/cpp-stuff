#include <iostream>
#include <string>
#include "../strings/string_helper_funcs.h"
#include "next_permutation.h"

std::string NextPermutation::nextPermutation(std::string s) {
    // Find first occurrence from the right of a pair of digits where the left-most is smaller than the right-most
    for (int i = s.size() - 2; i >= 0; i--) {
        for (int j = s.size() - 1; j > i; j--) {
            if (s[i] < s[j]) {
                // Swap them
                StringHelperFuncs::swap(s, i, j);

                // Reverse the digits to the right
                StringHelperFuncs::reverse(s, i+1, s.size()-1);

                return s;
            }
        }
    }

    // If no occurrence was found, reverse the whole string
    StringHelperFuncs::reverse(s, 0, s.size()-1);

    return s;
}

// int main() {
//     std::cout << NextPermutation::nextPermutation(6540) << std::endl;
// }