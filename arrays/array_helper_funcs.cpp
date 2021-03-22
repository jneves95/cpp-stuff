#include "array_helper_funcs.h"

void ArrayHelperFuncs::swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void ArrayHelperFuncs::reverse(int arr[], int i, int j) {
    while (i < j) {
        swap(arr, i++, j--);
    }
}

void ArrayHelperFuncs::swap(std::vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void ArrayHelperFuncs::reverse(std::vector<int> &arr, int i, int j) {
    while (i < j) {
        swap(arr, i++, j--);
    }
}
