/*
  Unique Binary Search Trees


Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

//Simple DP solutions to calculate number of BST
class Solution {
   public:
    int numTrees(int n) {
        if (n < 2) return 1;
        vector<int> ans(n + 1);
        ans[0] = 1;
        ans[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                ans[i] += ans[j] * ans[i - j - 1];
            }
        }

        return ans[n];
    }
};