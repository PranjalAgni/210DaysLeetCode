/*
  Partition Labels


A string S of lowercase English letters is given. We want to partition this
string into as many parts as possible so that each letter appears in at most one
part, and return a list of integers representing the size of these parts.



Example 1:

Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits
S into less parts.


Note:

S will have length in range [1, 500].
S will consist of lowercase English letters ('a' to 'z') only.

*/

// Solved using greedy approach. Time complexity is O(N)
class Solution {
   public:
    vector<int> partitionLabels(string S) {
        vector<int> answer;
        unordered_map<char, int> hashMap;
        int N = S.length();
        for (int idx = 0; idx < N; idx++) hashMap[S[idx]] = idx;

        int idx = 0;
        while (idx < N) {
            int end = hashMap[S[idx]];
            if (end == idx) {
                answer.push_back(1);  // as length of partition will only be 1
                idx += 1;
                continue;
            }
            int jidx = idx + 1;
            while (jidx != end) {
                end = max(end, hashMap[S[jidx]]);
                jidx += 1;
            }

            answer.push_back(jidx - idx + 1);
            idx = jidx + 1;
        }

        return answer;
    }
};