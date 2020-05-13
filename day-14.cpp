/*
Question: You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

direction can be 0 (for left shift) or 1 (for right shift). 
amount is the amount by which string s is to be shifted.
A left shift by 1 means remove the first character of s and append it to the end.
Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
Return the final string after all operations.

Example 1:

Input: s = "abc", shift = [[0,1],[1,2]]
Output: "cab"
Explanation: 
[0,1] means shift to left by 1. "abc" -> "bca"
[1,2] means shift to right by 2. "bca" -> "cab"


Example 2:

Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
Output: "efgabcd"
Explanation:  
[1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
[1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
[0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
[1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
*/

// Solution is O(N) & O(N)
class Solution {
   public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int dir = shift[0][0];
        int amt = shift[0][1];
        for (int i = 1; i < shift.size(); i++) {
            if (dir == shift[i][0]) {
                amt += shift[i][1];
            } else {
                if (shift[i][1] > amt) dir = shift[i][0];
                amt = abs(amt - shift[i][1]);
            }
        }

        int len = s.length();
        amt = amt % len;
        if (dir == 0) amt = len - amt;
        string ans = s;

        for (int i = 0; i < len; i++) {
            int nextPos = (i + amt) % len;
            ans[nextPos] = s[i];
        }

        return ans;
    }
};