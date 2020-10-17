/*
  Repeated DNA Sequences


All DNA is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and
'T', for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to
identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that
occur more than once in a DNA molecule.



Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]


Constraints:

0 <= s.length <= 105
s[i] is 'A', 'C', 'G', or 'T'.
*/

// Simple hash map solution, by generating substrings of length 10
class Solution {
   public:
    vector<string> findRepeatedDnaSequences(string s) {
        int N = s.size();

        if (N < 10) return {};

        vector<string> answer;
        unordered_map<string, int> hashMap;
        int idx = 0;

        while ((idx + 10) <= N) {
            string currStr = s.substr(idx, 10);
            hashMap[currStr] += 1;
            idx += 1;

            if (hashMap[currStr] == 2) answer.push_back(currStr);
        }

        return answer;
    }
};