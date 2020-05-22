/*
  Sort Characters By Frequency


Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

*/

// O(N) & O(N) solution using hashmap
class Solution {
   public:
    string frequencySort(string s) {
        unordered_map<char, int> hashMap;
        vector<char> charSet;

        for (char c : s) {
            hashMap[c] += 1;
            if (hashMap[c] == 1) charSet.push_back(c);
        }

        vector<pair<int, char>> vp;
        for (char ch : charSet) {
            vp.push_back({hashMap[ch], ch});
        }

        sort(vp.begin(), vp.end());

        string answer = "";
        for (int i = vp.size() - 1; i >= 0; i--) {
            int times = vp[i].first;
            while (times-- > 0) answer += vp[i].second;
        }

        return answer;
    }
};