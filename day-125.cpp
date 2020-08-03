/*
  Valid Palindrome


Given a string, determine if it is a palindrome, considering only alphanumeric
characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid
palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false


Constraints:

s consists only of printable ASCII characters.

*/

// Solved using O(N) & O(1) approach, beats 89.40% cpp submissions
class Solution {
   public:
    bool isValidCharacter(char ch) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') ||
            (ch >= '0' && ch <= '9')) {
            return true;
        }

        return false;
    }

    bool isCharacterEqual(char a, char b) {
        char aLower = tolower(a);
        char bLower = tolower(b);

        if (aLower == bLower) return true;
        return false;
    }

    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;
        int N = end;
        while (start < end) {
            while ((start <= N) && !isValidCharacter(s[start])) start += 1;
            while ((end >= 0) && !isValidCharacter(s[end])) end -= 1;

            if (!(start <= N && end >= 0)) return true;
            if (!isCharacterEqual(s[start], s[end])) return false;
            start += 1;
            end -= 1;
        }

        return true;
    }
};