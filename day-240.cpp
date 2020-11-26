/*
  Longest Substring with At Least K Repeating Characters

Given a string s and an integer k, return the length of the longest substring of
s such that the frequency of each character in this substring is greater than or
equal to k.


Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and
'b' is repeated 3 times.


Given a string s and an integer k, return the length of the longest substring of
s such that the frequency of each character in this substring is greater than or
equal to k.



Example 1:

Input: s = "aaabb", k = 3
Output: 3
Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input: s = "ababbc", k = 2
Output: 5
Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and
'b' is repeated 3 times.


Constraints:

1 <= s.length <= 104
s consists of only lowercase English letters.
1 <= k <= 105

*/

// Solved using map and recursion

class Solution {
   public:
    int longestSubstring(string s, int k) {
        int n = s.length();

        if (n == 0 || k > n) {
            return 0;
        }
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        int j = 0;
        while (j < n && mp[s[j]] >= k) {
            j++;
        }
        if (j >= n - 1) {
            return j;
        }
        int substring1 = longestSubstring(s.substr(0, j), k);
        while (j < n && mp[s[j]] < k) {
            j++;
        }
        int substring2;
        if (j < n) {
            substring2 = longestSubstring(s.substr(j), k);
        } else {
            substring2 = 0;
        }
        return max(substring1, substring2);
    }
};