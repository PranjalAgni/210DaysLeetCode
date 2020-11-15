/*
  Range Sum of BST


Given the root node of a binary search tree, return the sum of values of all
nodes with a value in the range [low, high].



Example 1:


Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
Output: 32
Example 2:


Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
Output: 23


Constraints:

The number of nodes in the tree is in the range [1, 2 * 104].
1 <= Node.val <= 105
1 <= low <= high <= 105
All Node.val are unique.
*/

// Simple recursive solution, iterating in the tree and comparing the values if
// it falls between the range
class Solution {
   public:
    void rangeSumBSTHelper(TreeNode* root, int low, int high, int& sum) {
        if (root == NULL) return;
        if (root->val >= low && root->val <= high) sum += root->val;
        rangeSumBSTHelper(root->left, low, high, sum);
        rangeSumBSTHelper(root->right, low, high, sum);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        rangeSumBSTHelper(root, low, high, sum);
        return sum;
    }
};