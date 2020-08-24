/*
  Sum of Left Leaves


Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively.
Return 24.

*/

// Solved using recursion, O(N) time & O(1) memory usage
class Solution {
   public:
    void leftLeavesHelper(TreeNode* root, int& sum, int flag) {
        if (root == NULL) return;

        if (flag == 1 && root->left == NULL && root->right == NULL)
            sum += root->val;

        leftLeavesHelper(root->left, sum, 1);
        leftLeavesHelper(root->right, sum, 2);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        leftLeavesHelper(root, sum, 0);
        return sum;
    }
};