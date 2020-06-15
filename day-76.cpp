/*
  Search in a Binary Search Tree

Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

In the example above, if we want to search the value 5, since there is no node with value 5, we should return NULL.

Note that an empty tree is represented by NULL, therefore you would see the expected output (serialized tree format) as [], not null.
*/

// Simple recursive solution based on properties of BST
class Solution {
   public:
    TreeNode* performSearch(TreeNode* root, int val) {
        if (root == NULL) return root;

        if (root->val == val) return root;
        TreeNode* answer;
        if (val < root->val)
            answer = performSearch(root->left, val);
        else
            answer = performSearch(root->right, val);

        return answer;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return performSearch(root, val);
    }
};