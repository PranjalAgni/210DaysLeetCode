/*
  Length of Last Word


Given a string s consists of upper/lower-case alphabets and empty space
characters ' ', return the length of last word (last word means the last
appearing word if we loop from left to right) in the string.

If the last word does not exist, return 0.

Note: A word is defined as a maximal substring consisting of non-space
characters only.

Example:

Input: "Hello World"
Output: 5

*/

// Simple O(N) & O(1) solution
// Beats 92.11 % of cpp submissions.

class Solution {
   public:
    int lengthOfLastWord(string s) {
        int N = s.length();
        int start = N - 1;
        int answer = 0;
        while (start >= 0 && s[start] == ' ') start -= 1;
        if (start < 0) return answer;
        while (start >= 0 && s[start] != ' ') {
            answer += 1;
            start -= 1;
        }

        return answer;
    }
};