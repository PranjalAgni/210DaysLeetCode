/*
  Remove Duplicate Letters

Given a string s, remove duplicate letters so that every letter appears once and
only once. You must make sure your result is the smallest in lexicographical
order among all possible results.


Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"


Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.

*/

// O(N) stack based solution
class Solution {
   public:
    string removeDuplicateLetters(string s) {
        string result = "";
        unordered_set<char> letters;
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 97]++;
        }
        for (int idx = 0; idx < s.size(); idx++) {
            freq[s[idx] - 97]--;
            if (letters.count(s[idx])) {
                continue;
            }
            while (result.size() > 0 && s[idx] < result.back() &&
                   freq[result.back() - 97] > 0) {
                letters.erase(result.back());
                result.pop_back();
            }
            result.push_back(s[idx]);
            letters.insert(s[idx]);
        }
        return result;
    }
};