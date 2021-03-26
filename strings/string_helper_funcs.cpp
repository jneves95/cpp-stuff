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

bool StringHelperFuncs::isSubset(std::string s, std::string t) {
    auto s_it = s.begin();
    auto t_it = t.begin();

    while (t_it != t.end() && s_it != s.end()) {
        if (*t_it == *s_it) s_it++;
        t_it++;
    }

    return s_it == s.end();
}

bool StringHelperFuncs::isSubstring(std::string s, std::string t) {
    auto s_it = s.begin();
    auto t_it = t.begin();

    while (t_it != t.end() && s_it != s.end()) {
        if (*t_it == *s_it) s_it++;
        else s_it = s.begin();
        t_it++;
    }

    return s_it == s.end();
}