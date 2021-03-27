#include <iostream>
#include <string>
#include <chrono>

/**
 * LeetCode 27 March 2021 challenge
 * 
 * Given a string, returns the number of palindromes found in said string. Any valid substring can be a palindrome, even single characters.
 */

using namespace std;

// Verifies whether a substring is a palindrome
bool isPalindrome(string s, int left, int right) {
    for (int i = left, j = right; i < j; i++, j--) {
        if (s[i] != s[j]) return false;
    }
    return true;
}

// Brute-force approach: Check if every substring is a palindrome
int countPalindromesBrute(string s) {
    int count = 0;

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j <= i; j++) {
            count += isPalindrome(s, j, i);
        }
    }

    return count;
}

// Dynamic programming approach - start by establishing the base cases for smaller palindromes:
// A single character is automatically a palindrome, and 2 equal characters are palindromes as well.
// These two cases can be the center for any other larger palindrome, as long as the end characters are equal.
// We will use a DP matrix to store whether or not a substring starting from I and ending in J is a palindrome or not, and build from there.
int countPalindromes(string s) {
    int count = 0;
    int n = s.size();

    if (n == 0) return 0;

    bool dp[n][n];
    fill_n(*dp, n * n, false);  // Since a matrix is just a contiguous array, we can just use a pointer for its first position and fill the values continuously

    // Single character palindromes
    for (int i = 0; i < n; i++, count++) {
        dp[i][i] = true;
    }

    // Double character palindromes
    for (int i = 0; i < n - 1; i++) {
        dp[i][i+1] = (s[i] == s[i+1]);
        count += dp[i][i+1];
    }

    // All other substrings - from length 3 and up
    for (int len = 3; len <= n; len++) {    // Increasing length
        for (int i = 0, j = i + len - 1; j < n; i++, j++) { // Start/end characters moving forward
            dp[i][j] = (dp[i+1][j-1] && s[i] == s[j]);
            count += dp[i][j];
        }
    }

    return count;
}

int main() {
    cout << countPalindromesBrute("aaa") << endl;
    cout << countPalindromesBrute("abc") << endl;
    cout << countPalindromesBrute("aabccbaa") << endl;

    cout << countPalindromes("aaa") << endl;
    cout << countPalindromes("abc") << endl;
    cout << countPalindromes("aabccbaa") << endl;
}