/*

  Kth Smallest Element in a BST

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3

 */

// O(height(tree)) & O(1) solution
class Solution {
   public:
    void inorder(TreeNode* root, int k, vector<int>& nums) {
        if (root == NULL) return;
        inorder(root->left, k, nums);
        nums[0] += 1;
        if (nums[0] == k) {
            nums[1] = root->val;
            return;
        }
        inorder(root->right, k, nums);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums(2, 0);
        inorder(root, k, nums);
        return nums[1];
    }
};