#include "string_helper_funcs.h"
#include <iostream>
#include <vector>

using namespace std;

vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
    vector<string> univ;    

    int univCount[26] = {0};    // Keeps the maximum number of times a letter occurs in a word of B
    int total = 0;   // The total number of letters needed to match against a word of A

    for (string b : B) {
        int bCount[26] = {0};

        for (char c : b) {
            int i = c - 'a';
            if (++bCount[i] > univCount[i]) {
                univCount[i]++;
                total++;
            }
        }
    }

    // For word in A to be universal, it has to contain all characters in our universal counter
    for (string a : A) {
        int matches = 0;
        int aCount[26] = {0};

        for (char c : a) {
            int i = c - 'a';
            if (aCount[i] < univCount[i]) {
                aCount[i]++;
                matches++;
            }

            if (matches == total) { // Found a universal word, don't need to check the rest of the string
                univ.push_back(a);
                break;
            }
        }
    }

    return univ;
}

int main() {
    vector<string> A = {"amazon","apple","facebook","google","leetcode"};
    vector<string> B1 = {"e", "o"};
    vector<string> B2 = {"l", "e"};
    vector<string> B3 = {"e", "oo"};
    vector<string> B4 = {"lo","eo"};
    vector<string> B5 = {"ec","oc","ceo"};

    vector<vector<string>> vecs = {B1, B2, B3, B4, B5};

    for (vector<string> B : vecs) {
        for (string s : wordSubsets(A, B)) {
            std::cout << "\"" << s << "\" ";
        }

        std::cout << std::endl;
    }
}