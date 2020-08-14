/*
  Longest Palindrome


Given a string which consists of lowercase or uppercase letters, find the length
of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*/

// Simple O(N) solution. Maintaning a map to store characters,
// then computing length of longest string based on it

class Solution {
   public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freqMap;
        for (char ch : s) {
            freqMap[ch] += 1;
        }

        int answer = 0;
        bool isOneSeen = false;

        for (auto& map : freqMap) {
            int freq = map.second;
            if (freq & 1 == 1) {
                isOneSeen = true;
                freq -= 1;
            }
            answer += freq;
        }

        if (isOneSeen) answer += 1;
        return answer;
    }
};