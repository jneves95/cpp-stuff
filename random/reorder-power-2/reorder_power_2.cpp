#include <iostream>
#include <string>
#include <array>
#include "../next-permutation/next_permutation.h"

// Checks whether an integer is a power of 2
bool isPowerOf2(int n) {
    return (n & (n - 1)) == 0;
}

// My first brute-force approach
bool reorderPowerOf2Brute(int n) {
    // First convert this integer into a string representation of its digits
    std::string s = std::to_string(n);
    std::string test = s;

    do {
        if (test.at(0) != '0') {
            int a = std::stoi(test);
            if (isPowerOf2(a)) return true;
        }
        test = NextPermutation::nextPermutation(test);
    } while (test != s);

    return false;
}

// AUX: Print array
void print(std::array<int, 10> arr) {
    std::cout << "[";

    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << "]"; 
}

// Counts the occurrence of all digits in a given integer and returns an array with the respective counts
std::array<int, 10> digitCount(int n) {
    std::array<int, 10> arr = {};

    while (n != 0) {
        arr[n % 10]++;
        n /= 10;
    }

    return arr;
}

// Better approach: for all powers of 2 an integer can be (up to 2^31) we can compare the digit count of these 31 numbers and our given integer.
bool reorderPowerOf2(int n) {
    std::array<int, 10> nCount = digitCount(n);

    for (int i = 0; i < 31; i++) {
        std::array<int, 10> power = digitCount(1 << i);
        if (nCount == power) return true;
    }

    return false;
}

int main() {
    std::cout << "0: " << reorderPowerOf2(0) << std::endl; // false
    std::cout << "1: " << reorderPowerOf2(1) << std::endl; // true
    std::cout << "2: " << reorderPowerOf2(2) << std::endl; // true
    std::cout << "3: " << reorderPowerOf2(3) << std::endl; // false
    std::cout << "215: " << reorderPowerOf2(215) << std::endl; // true
    std::cout << "216: " << reorderPowerOf2(216) << std::endl; // false
    std::cout << "9046: " << reorderPowerOf2(9046) << std::endl; // true
}