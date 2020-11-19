/*
  Decode String


Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the
square brackets is being repeated exactly k times. Note that k is guaranteed to
be a positive integer.

You may assume that the input string is always valid; No extra white spaces,
square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits
and that digits are only for those repeat numbers, k. For example, there won't
be input like 3a or 2[4].



Example 1:

Input: s = "3[a]2[bc]"
Output: "aaabcbc"
Example 2:

Input: s = "3[a2[c]]"
Output: "accaccacc"
Example 3:

Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
Example 4:

Input: s = "abc3[cd]xyz"
Output: "abccdcdcdxyz"


Constraints:

1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].

*/

// Iterative solution
// Your memory usage beats 48.56 % of cpp submissions.

class Solution {
   public:
    string repeat(string str, int times) {
        string res = "";
        for (int i = 0; i < times; i++) res += str;
        return res;
    }

    string decodeString(string s) {
        int i = 0;
        while (i < s.size()) {
            if (s[i] != ']') {
                i++;
                continue;
            }

            int j = i;
            while (s[j] != '[') j--;

            string letters_to_repeat = s.substr(j + 1, i - j - 1);
            int k = j;
            j--;
            while ((j > 0) && (isdigit(s[j]))) j--;

            if (j != 0) j++;
            int times_to_repeat = stoi(s.substr(j, k - j));

            s.replace(j, i - j + 1, repeat(letters_to_repeat, times_to_repeat));

            i = j + letters_to_repeat.size() * times_to_repeat;
        }
        return s;
    }
};