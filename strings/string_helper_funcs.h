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

    // Returns a lower-case string representation of the given string
    static std::string toLowerCase(std::string s);

    /**
     * Returns whether a given string S is an ordered subset of a given string T.
     * In other words, if the characters of S are sequentially found in T, not necessarily consecutively.
     * @param s: string to look for
     * @param t: string to check against
     */
    static bool isOrderedSubset(std::string s, std::string t);

    /**
     * Returns whether a given string S is a substring of a given string T.
     * @param s: string to look for
     * @param t: string to check against
     */
    static bool isSubstring(std::string s, std::string t);
};

#endif