/*
  Binary Tree Maximum Path Sum

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/
class Solution {
    int max_path_sum;

   public:
    int maxPathSum(TreeNode* root) {
        max_path_sum = INT_MIN;
        pathSum(root);
        return max_path_sum;
    }

    int pathSum(TreeNode* node) {
        if (node == NULL) return 0;
        int left = max(0, pathSum(node->left));
        int right = max(0, pathSum(node->right));
        max_path_sum = max(max_path_sum, left + right + node->val);
        return max(left, right) + node->val;
    }
};