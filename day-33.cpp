/*
Ransom Note
Solution
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

class Solution {
   public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hashMap;

        for (char ch : magazine) {
            hashMap[ch] += 1;
        }

        for (char ch : ransomNote) {
            if (hashMap[ch] == 0) return false;
            hashMap[ch] -= 1;
        }

        return true;
    }
};