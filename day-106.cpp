/*
  Reverse Words in a String


Given an input string, reverse the string word by word.

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.


*/

// Simple c++ solution beats 97.87 % of cpp submissions.
// O(N) & O(N) approach
class Solution {
   public:
    string reverseWords(string s) {
        if (s == "") return s;
        int startPos = 0;
        int endPos = s.size() - 1;

        // get first valid character position
        while (startPos <= endPos && s[startPos] == ' ') startPos += 1;
        // get last valid character position
        while (endPos >= 0 && s[endPos] == ' ') endPos -= 1;

        // if any one is invalid, then string does not contains alphanumeric chars
        if (startPos == s.size() || endPos == -1) return "";

        string str = "";
        bool isSpace = false;

        // compute the string to perform the logic on
        for (int idx = startPos; idx <= endPos; idx++) {
            if (s[idx] != ' ') {
                str += s[idx];
                isSpace = true;
            } else {
                if (isSpace) {
                    str += " ";
                    isSpace = false;
                }
            }
        }

        int start = 0;
        int end = str.size() - 1;

        // reversing entire string
        while (start < end) {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start += 1;
            end -= 1;
        }

        int low = 0;
        // reversing word by word
        for (int high = 0; high < str.size(); high++) {
            if (str[high] == ' ') {
                reverse(str.begin() + low, str.begin() + high);
                low = high + 1;
            }
        }

        // for last word
        reverse(str.begin() + low, str.end());

        return str;
    }
};