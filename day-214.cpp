/*
  Recover Binary Search Tree


You are given the root of a binary search tree (BST), where exactly two nodes of
the tree were swapped by mistake. Recover the tree without changing its
structure.

Follow up: A solution using O(n) space is pretty straight forward. Could you
devise a constant space solution?

Input: root = [1,3,null,null,2]
Output: [3,1,null,null,2]
Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes
the BST valid.

Input: root = [3,1,4,null,null,2]
Output: [2,1,4,null,null,3]
Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and
3 makes the BST valid.

*/

// Simple O(N) & O(1) solution using inorder traversal

class Solution {
   public:
    vector<pair<TreeNode*, TreeNode*>> vec;
    TreeNode* prev = NULL;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (prev && prev->val > root->val) vec.push_back({prev, root});
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        if (vec.size() == 1) swap(vec[0].first->val, vec[0].second->val);
        if (vec.size() == 2) swap(vec[0].first->val, vec[1].second->val);
    }
};