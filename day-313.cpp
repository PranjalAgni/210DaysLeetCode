/*
Shortest Distance to a Character

Solution
Given a string s and a character c that occurs in s, return an array of integers
answer where answer.length == s.length and answer[i] is the shortest distance
from s[i] to the character c in s.



Example 1:

Input: s = "loveleetcode", c = "e"
Output: [3,2,1,0,1,0,0,1,2,2,1,0]
Example 2:

Input: s = "aaab", c = "b"
Output: [3,2,1,0]


Constraints:

1 <= s.length <= 104
s[i] and c are lowercase English letters.
c occurs at least once in s.

*/

// Simple O(N) solution
class Solution {
   public:
    vector<int> shortestToChar(string s, char c) {
        int len = s.size();
        vector<int> targetPosition;
        vector<int> answer(len);

        for (int idx = 0; idx < len; idx++) {
            if (s[idx] == c) {
                targetPosition.push_back(idx);
            }
        }

        int limit = targetPosition.size() - 1;

        int pos = 0;
        for (int idx = 0; idx < len; idx++) {
            char ch = s[idx];
            if (ch == c) {
                answer[idx] = 0;
                if (pos < limit) pos += 1;

            } else {
                int distance = abs(idx - targetPosition[pos]);
                if (pos != 0) {
                    distance =
                        min(distance, abs(idx - targetPosition[pos - 1]));
                }
                answer[idx] = distance;
            }
        }

        return answer;
    }
};