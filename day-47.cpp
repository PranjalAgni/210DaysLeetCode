/*
  Find All Anagrams in a String


Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

// O(N) & O(N) sliding-window approach beats 98% of cpp solutions
class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> answer;
        if (s.length() == 0) return answer;

        vector<int> hashMap(26, 0);

        for (char ch : p) {
            hashMap[ch - 'a'] += 1;
        }

        int left = 0;
        int right = 0;
        int count = p.length();

        while (right < s.length()) {
            if (hashMap[s[right] - 'a'] > 0) {
                count -= 1;
            }

            hashMap[s[right] - 'a'] -= 1;
            right += 1;

            if (count == 0) answer.push_back(left);

            if (right - left == p.length()) {
                if (hashMap[s[left] - 'a'] >= 0) count += 1;
                hashMap[s[left] - 'a'] += 1;
                left += 1;
            }
        }

        return answer;
    }
};