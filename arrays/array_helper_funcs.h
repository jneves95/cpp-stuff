#ifndef ARRAY_HELPER_FUNCS_H
#define ARRAY_HELPER_FUNCS_H

#include <vector>

// Helper functions for integer arrays
class ArrayHelperFuncs {
public:
    // Swaps values in specified positions
    static void swap(int arr[], int i, int j);
    static void swap(std::vector<int> &arr, int i, int j);

    // Given an array Arr, reverses the subarray from position I to position J
    static void reverse(int arr[], int i, int j);
    
    static void reverse(std::vector<int> &arr, int i, int j);
    static void reverse(std::vector<int> &arr) { reverse(arr, 0, arr.size()-1); }
};

#endif