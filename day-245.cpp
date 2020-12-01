/*
  Maximum Depth of Binary Tree


Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from
the root node down to the farthest leaf node.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
Example 3:

Input: root = []
Output: 0
Example 4:

Input: root = [0]
Output: 1


Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100
*/

// Simple recursive solution
class Solution {
   public:
    void maxDepthHelper(TreeNode* root, int current, int& maxDepth) {
        if (root == NULL) return;
        maxDepth = max(maxDepth, current);
        if (root->left) maxDepthHelper(root->left, current + 1, maxDepth);
        if (root->right) maxDepthHelper(root->right, current + 1, maxDepth);
    }

    int maxDepth(TreeNode* root) {
        int maxDepth = 0;
        int current = 1;
        maxDepthHelper(root, current, maxDepth);
        return maxDepth;
    }
};