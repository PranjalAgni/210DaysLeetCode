/*

  House Robber III

The thief has found himself a new place for his thievery again. There is only
one entrance to this area, called the "root." Besides the root, each house has
one and only one parent house. After a tour, the smart thief realized that "all
houses in this place forms a binary tree". It will automatically contact the
police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting
the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

// DP memoized solution

class Solution {
   public:
    unordered_map<TreeNode*, int> memo;
    int memoisedRob(TreeNode* root) {
        return memo.find(root) != end(memo) ? memo[root]
                                            : memo[root] = rob(root);
    }
    int rob(TreeNode* root) {
        return root ? max(root->val +
                              (root->left ? memoisedRob(root->left->left) +
                                                memoisedRob(root->left->right)
                                          : 0) +
                              (root->right ? memoisedRob(root->right->left) +
                                                 memoisedRob(root->right->right)
                                           : 0),
                          memoisedRob(root->left) + memoisedRob(root->right))
                    : 0;
    }
};