/*
Palindrome Partitioning

Solution
Given a string s, partition s such that every substring of the partition is a
palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.



Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]


Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/

// Solved using backtracking
class Solution {
   public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    void helper(string s, vector<vector<string>> &result, vector<string> temp) {
        if (s.size() == 0) {
            result.push_back(temp);
        }
        for (int i = 0; i < s.size(); i++) {
            string leftPar = s.substr(0, i + 1);
            if (isPalindrome(leftPar)) {
                temp.push_back(leftPar);
                helper(s.substr(i + 1), result, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        helper(s, result, temp);
        return result;
    }
};