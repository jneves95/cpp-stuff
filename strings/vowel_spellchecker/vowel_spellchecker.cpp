#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

/**
 * LeetCode 22 March 2021 challenge.
 * 
 * My first accepted solution - not the most efficient.
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

    // Checks whether two strings are a case-insensitive match
    bool isMatchCase(string s, string t) {
        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            if (tolower(s[i]) != tolower(t[i])) return false;
        }

        return true;
    }

    // Checks whether two strings are a match by replacing vowels (also case-insensitive)
    bool isMatchVowels(string s, string t) {
        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            if (tolower(s[i]) != tolower(t[i]) && (!isVowel(s[i]) || !isVowel(t[i]))) return false; // If different characters and any of them is not a vowel, not a match
        }

        return true;
    }

    // Simple hash function to reduce time complexity
    int hash(string s) {
        int h = 0;

        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) h += 1;
            else h += 'z' - tolower(s[i]);
            h *= 10;
        }

        return h;
    }

    vector<string> spellcheck(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<int, vector<string>> hashTable;

        // Populate our hash table
        for (string w : wordlist) {
            int h = hash(w);
            hashTable[h].push_back(w);
        }

        vector<string> result;

        for (string q : queries) {
            int h = hash(q);
            string r = "";  // Default empty match
            bool capFlag = false;

            for (string w : hashTable[h]) {
                if (q == w) {   // Exact match
                    r = q;  
                    break;
                }
                else if (isMatchCase(q, w) && !capFlag) {
                    capFlag = true;
                    r = w;
                }
                else if (isMatchVowels(q, w) && r == "") {
                    r = w;
                }
            }

            result.push_back(r);
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