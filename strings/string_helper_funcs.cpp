#include "string_helper_funcs.h"

void StringHelperFuncs::swap(std::string &s, int i, int j) {
    int temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

void StringHelperFuncs::reverse(std::string &s, int i, int j) {
    while (i < j) {
        swap(s, i++, j--);
    }
}

std::string StringHelperFuncs::toLowerCase(std::string s) {
    std::string res = "";
    for (char c : s) {
        res.push_back(tolower(c));
    }
    return res;
}
