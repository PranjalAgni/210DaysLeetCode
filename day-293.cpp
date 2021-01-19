/*
Longest Palindromic Substring

Solution
Given a string s, return the longest palindromic substring in s.



Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"


Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/

// Simple solution
class Solution {
   public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;
        int start = 0, length = 1;

        for (unsigned i = 1;
             i < s.size() * 2 - 1 && (s.size() - 1 - i / 2) >= length / 2;
             i++) {
            int left = i / 2, right = i % 2 == 0 ? left : left + 1;

            if (s[right] != s[left]) continue;

            do {
                right++;
                left--;
            } while (right <= s.size() - 1 && left >= 0 && s[right] == s[left]);

            if (right - left - 1 > length) {
                start = left + 1;
                length = right - left - 1;
            }
        }

        return s.substr(start, length);
    }
};