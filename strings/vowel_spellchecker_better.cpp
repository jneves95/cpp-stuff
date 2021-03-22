#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "string_helper_funcs.h"

/**
 * LeetCode 22 March 2021 challenge.
 * 
 * A more efficient approach - multiple hash tables.
 */

using namespace std;

class VowelSpellchecker {
public:
    // Checks whether a given character is a vowel
    bool isVowel(char c) {
        c = tolower(c); // Convert to lower-case

        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        for (char v : vowels) {
            if (c == v) return true;
        }
        return false;
    }

    // Replaces all vowels in a string with 'a'
    string devowel(string s) {
        string res = "";

        for(char c : s) {
            if (isVowel(c)) res.push_back('a');
            else res.push_back(c);
        }

        return res;
    }

    vector<string> spellcheck(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> words_exact;
        unordered_map<string, string> words_cap;
        unordered_map<string, string> words_devow;

        // Populate our hash tables
        for (string w : wordlist) {
            words_exact.insert(w);

            string lower = StringHelperFuncs::toLowerCase(w);
            words_cap.emplace(lower, w); // Inserts the first word from the list with this lower-case string

            string devow = devowel(lower);
            words_devow.emplace(devow, w);   // Inserts the first word from the list with this devoweled lower-case string
        }

        vector<string> result;

        for (string q : queries) {
            if (auto it = words_exact.find(q); it != words_exact.end()) {   // Try to find an exact match
                result.push_back(q);
                continue;
            }
            
            string lower = StringHelperFuncs::toLowerCase(q);
            if (auto it = words_cap.find(lower); it != words_cap.end()) {   // Try to find a capitalization match
                result.push_back(it->second);
                continue;
            }

            string devow = devowel(lower);
            if (auto it = words_devow.find(devow); it != words_devow.end()) {   // Try to find a switched-vowel match
                result.push_back(it->second);
                continue;
            }

            result.push_back("");   // If no match, return empty string
        }

        return result;
    }
};

int main() {
    VowelSpellchecker vs;

    // cout << vs.isVowel('b') << endl;                 // false
    // cout << vs.isVowel('e') << endl;                 // true
    // cout << vs.isMatch("kiTe", "kotA") << endl;      // true
    // cout << vs.isMatch("kiTe", "kolA") << endl;      // false
    // cout << vs.isMatch("kiTe", "kotAa") << endl;     // false
    // cout << vs.isMatch("kiTe", "kotr") << endl;      // false

    vector<string> wordlist = {"KiTe","kite","hare","Hare"};
    vector<string> queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
    vector<string> output = vs.spellcheck(wordlist, queries);

    for (string s : output) {
        cout << "\"" + s + "\" ";
    }

    cout << endl;
}