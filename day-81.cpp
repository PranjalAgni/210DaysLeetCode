/*
  Permutation Sequence


The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"

*/

// Idea is to use factorial.
class Solution {
   public:
    string getPermutation(int n, int k) {
        vector<int> digits(n);
        vector<int> facts(n);

        digits[0] = 1;
        facts[0] = 1;

        for (int i = 1; i < n; i++) {
            digits[i] = i + 1;
            facts[i] = facts[i - 1] * (i + 1);
        }

        string res = "";

        while (res.length() < n - 1) {
            int groups = facts[facts.size() - 2];
            int nextDigit = (k - 1) / groups;
            res += to_string(digits[nextDigit]);
            digits.erase(digits.begin() + nextDigit);
            facts.pop_back();
            k = k % groups;

            if (k == 0) {
                for (int i = digits.size() - 1; i >= 0; i--) {
                    res += to_string(digits[i]);
                }
            }
        }

        if (res.size() < n) res += to_string(digits[0]);

        return res;
    }
};