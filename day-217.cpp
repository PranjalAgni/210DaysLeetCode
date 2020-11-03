/*
  Consecutive Characters


Given a string s, the power of the string is the maximum length of a non-empty
substring that contains only one unique character.

Return the power of the string.



Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.
Example 3:

Input: s = "triplepillooooow"
Output: 5
Example 4:

Input: s = "hooraaaaaaaaaaay"
Output: 11
Example 5:

Input: s = "tourist"
Output: 1


Constraints:

1 <= s.length <= 500
s contains only lowercase English letters.
*/

// Simple O(N) solution beats 86.98 % of cpp submissions.
class Solution {
   public:
    int maxPower(string s) {
        int N = s.size();
        int currMax = 0;
        int ansMax = 1;
        bool isStart = true;
        for (int idx = 1; idx < N; idx++) {
            if (s[idx] == s[idx - 1]) {
                if (isStart) {
                    currMax += 1;
                    isStart = false;
                }

                currMax += 1;
            } else {
                ansMax = max(ansMax, currMax);
                currMax = 0;
                isStart = true;
            }
        }

        ansMax = max(ansMax, currMax);

        return ansMax;
    }
};