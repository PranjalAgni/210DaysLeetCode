/*
  Word Pattern


Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter
in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains
lowercase letters that may be separated by a single space.

*/

// O(N) approach, using hashMaps to check if the order is correct
class Solution {
   public:
    bool wordPattern(string pattern, string str) {
        stringstream splitterStream(str);
        char SPACE_DELIM = ' ';
        string word;
        vector<string> words;
        while (getline(splitterStream, word, SPACE_DELIM)) {
            words.push_back(word);
        }

        // if length isn't same then it is always false
        if (words.size() != pattern.length()) return false;

        unordered_map<char, string> hashMap;
        unordered_map<string, bool> wordsMap;

        int N = words.size();

        for (int idx = 0; idx < N; idx++) {
            if (hashMap.count(pattern[idx]) > 0) {
                string currWord = hashMap[pattern[idx]];
                if (currWord != words[idx]) return false;
            } else {
                if (wordsMap[words[idx]]) return false;
                hashMap[pattern[idx]] = words[idx];
                wordsMap[words[idx]] = true;
            }
        }

        return true;
    }
};