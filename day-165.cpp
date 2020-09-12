/*
  Combination Sum III


Find all possible combinations of k numbers that add up to a number n, given
that only numbers from 1 to 9 can be used and each combination should be a
unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]

*/

// Solved using back tracking and recursion
class Solution {
   public:
    vector<vector<int>> answer;
    void computeAllCombinations(vector<int>& combination, int k, int n,
                                int start) {
        if (k == combination.size()) {
            if (n == 0) answer.push_back(combination);
            return;
        }

        for (int idx = start; idx <= 9; idx++) {
            combination.push_back(idx);
            computeAllCombinations(combination, k, n - idx, idx + 1);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        computeAllCombinations(combination, k, n, 1);
        return answer;
    }
};