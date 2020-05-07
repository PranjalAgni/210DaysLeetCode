/*
Cousins in Binary Tree

Solution
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
 
*/

class Pair {
   public:
    TreeNode* parent;
    int level;

    Pair(TreeNode* mParent, int mLevel) {
        parent = mParent;
        level = mLevel;
    }
};

class Solution {
   public:
    Pair* isCousinHelper(TreeNode* root, int val, TreeNode* parent, int level) {
        if (root == NULL) {
            return new Pair(NULL, -1);
        }

        if (root->val == val) {
            return new Pair(parent, level);
        }

        Pair* leftPair = isCousinHelper(root->left, val, root, level + 1);

        Pair* rightPair = isCousinHelper(root->right, val, root, level + 1);

        return leftPair->parent == NULL ? rightPair : leftPair;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        Pair* pairx = isCousinHelper(root, x, NULL, 0);
        Pair* pairy = isCousinHelper(root, y, NULL, 0);

        if (pairx->level == pairy->level && pairx->parent != pairy->parent) {
            return true;
        }

        return false;
    }
};