/*
  Invert Binary Tree
*/

// Recursive solution
class Solution {
   public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        }

        TreeNode* tempNode;
        invertTree(root->left);
        invertTree(root->right);

        tempNode = root->left;
        root->left = root->right;
        root->right = tempNode;
        return root;
    }
};