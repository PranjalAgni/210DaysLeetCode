/*
Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in
height by no more than 1.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true


Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/

// Simple O(H) solution
// H = height of the tree
class Solution {
   public:
    int height(TreeNode* node) {
        if (node == NULL) return 0;
        int left = height(node->left);
        int right = height(node->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
        return max(left, right) + 1;
    }

    bool isBalanced(TreeNode* root) { return height(root) != -1; }
};