/*

  Detect Capital

Given a word, you need to judge whether the usage of capitals in it is right or
not.

We define the usage of capitals in a word to be right when one of the following
cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.


Example 1:

Input: "USA"
Output: True


Example 2:

Input: "FlaG"
Output: False


Note: The input will be a non-empty word consisting of uppercase and lowercase
latin letters.


*/

// Simple O(N) & O(1) solution
class Solution {
   public:
    bool detectCapitalUse(string word) {
        int N = word.length();

        int numCapitalLetters = 0;
        bool firstLetterCapital = false;

        for (int idx = N - 1; idx >= 0; idx--) {
            char current = word[idx];
            if (current >= 'A' && current <= 'Z') {
                if (idx == 0 && numCapitalLetters == 0)
                    firstLetterCapital = true;
                numCapitalLetters += 1;
            }
        }

        if (numCapitalLetters == N || numCapitalLetters == 0 ||
            firstLetterCapital)
            return true;
        return false;
    }
};