/*
  Minimum Depth of Binary Tree

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root
node down to the nearest leaf node.

Note: A leaf is a node with no children.


Input: root = [3,9,20,null,null,15,7]
Output: 2
Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5


Constraints:

The number of nodes in the tree is in the range [0, 105].
-1000 <= Node.val <= 1000

*/

// Simple recursive solution
class Solution {
   public:
    void minDepthHelper(TreeNode* root, int& minDepthCount,
                        int currDepthCount) {
        if (!root) return;

        currDepthCount += 1;
        if (root->left == NULL && root->right == NULL) {
            minDepthCount = min(currDepthCount, minDepthCount);
            currDepthCount = 0;
        }

        minDepthHelper(root->left, minDepthCount, currDepthCount);
        minDepthHelper(root->right, minDepthCount, currDepthCount);
    }

    int minDepth(TreeNode* root) {
        int minDepthCount = INT_MAX;
        minDepthHelper(root, minDepthCount, 0);
        return minDepthCount == INT_MAX ? 0 : minDepthCount;
    }
};