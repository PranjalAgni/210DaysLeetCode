/*
  Permutation in String


Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.


Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False
 

Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

// O(N) & O(1) beats 76.14 % of cpp submissions.

class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() == 0) return false;

        vector<int> charCount(26, 0);

        for (char ch : s1) {
            charCount[ch - 'a'] += 1;
        }

        int left = 0;
        int right = 0;
        int count = s1.length();

        while (right < s2.length()) {
            if (charCount[s2[right] - 'a'] > 0) {
                charCount[s2[right] - 'a'] -= 1;
                count -= 1;
                right += 1;
                if (count == 0) return true;
            } else if (left == right) {
                left += 1;
                right += 1;
            } else {
                charCount[s2[left] - 'a'] += 1;
                left += 1;
                count += 1;
            }
        }

        return false;
    }
};