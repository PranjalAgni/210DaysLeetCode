/*
  Buddy Strings


Given two strings A and B of lowercase letters, return true if you can swap two
letters in A so the result is equal to B, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that
i != j and swapping the characters at A[i] and A[j]. For example, swapping at
indices 0 and 2 in "abcd" results in "cbad".



Example 1:

Input: A = "ab", B = "ba"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'b' to get "ba", which is equal
to B. Example 2:

Input: A = "ab", B = "ab"
Output: false
Explanation: The only letters you can swap are A[0] = 'a' and A[1] = 'b', which
results in "ba" != B. Example 3:

Input: A = "aa", B = "aa"
Output: true
Explanation: You can swap A[0] = 'a' and A[1] = 'a' to get "aa", which is equal
to B. Example 4:

Input: A = "aaaaaaabc", B = "aaaaaaacb"
Output: true
Example 5:

Input: A = "", B = "aa"
Output: false


*/

// Simple O(N) solution, using bitsets
class Solution {
   public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size() || A.size() < 2) return false;
        string sa, sb;
        bitset<128> bits{0};
        bool dup = false;
        for (int i = 0; i < A.size() && sa.size() <= 2; ++i) {
            if (A[i] != B[i]) {
                sa += A[i], sb += B[i];
            } else {
                dup |= bits.test(A[i]);
                bits.set(A[i]);
            }
        }
        if (sa.size() == 2) {
            swap(sa[0], sa[1]);
            return sa == sb;
        }
        return sa.empty() && dup;
    }
};