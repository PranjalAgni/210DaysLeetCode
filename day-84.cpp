/*
  Count Complete Tree Nodes


Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
 */

//Simple recursive based solution to count nodes
class Solution {
   public:
    void computeNodes(TreeNode* root, int& count) {
        if (root == NULL) return;

        count += 1;
        computeNodes(root->left, count);
        computeNodes(root->right, count);
    }

    int countNodes(TreeNode* root) {
        int count = 0;
        computeNodes(root, count);
        return count;
    }
};