/*
  Construct Binary Tree from Inorder and Postorder Traversal



Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
     */

// Simple recursive solution to build the tree
class Solution {
   public:
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postEnd) {
        if (postEnd < 0 || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int idx = inStart;
        for (; idx < inEnd; idx++) {
            if (inorder[idx] == root->val) break;
        }

        root->left = buildTreeHelper(inorder, postorder, inStart, idx - 1, postEnd - 1 + idx - inEnd);
        root->right = buildTreeHelper(inorder, postorder, idx + 1, inEnd, postEnd - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
    }
};