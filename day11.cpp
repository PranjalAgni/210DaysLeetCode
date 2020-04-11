/*
Question: Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    

Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.
*/

// O(N) & O(N)(recursion stack internally used.)
class Solution {
   public:
    int height(TreeNode* root, int& ans) {
        if (root == NULL) return 0;

        int leftH = height(root->left, ans);
        int rightH = height(root->right, ans);

        ans = max(ans, 1 + leftH + rightH);
        return 1 + max(leftH, rightH);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        int ans = INT_MIN;
        int treeHeight = height(root, ans);
        return ans - 1;
    }
};