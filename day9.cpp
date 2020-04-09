/*
Question: Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

Examples: 
Input: S = "ab#c", T = "ad#c"
Output: true
Explanation: Both S and T become "ac".

Input: S = "ab##", T = "c#d#"
Output: true
Explanation: Both S and T become "".

Input: S = "a##c", T = "#a#c"
Output: true
Explanation: Both S and T become "c".

Input: S = "a#c", T = "b"
Output: false
Explanation: S becomes "c" while T becomes "b".
*/

class Solution {
   public:
    string computeString(string str) {
        int len = str.length();
        int idx = 0;
        for (int i = 0; i < len; i++) {
            if (str[i] == '#' && idx == 0) continue;
            if (str[i] == '#')
                idx -= 1;
            else
                str[idx++] = str[i];
        }
        str = str.substr(0, idx);
        return str;
    }
    bool backspaceCompare(string S, string T) {
        S = computeString(S);
        T = computeString(T);
        if (S == T) return true;
        return false;
    }
};