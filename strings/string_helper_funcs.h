#ifndef STRING_HELPER_FUNCS_H
#define STRING_HELPER_FUNCS_H

#include <string>

// Helper functions for integer arrays
class StringHelperFuncs {
public:
    // Swaps characters in specified positions
    static void swap(std::string &s, int i, int j);

    // Given a string S, reverses the substring from position I to position J
    static void reverse(std::string &s, int i, int j);
};

#endif