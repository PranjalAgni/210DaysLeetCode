/*
Question: Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

 

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

*/
class Solution {
   public:
    TreeNode* buildTree(vector<int>& preorder, int low, int high) {
        if (low > high) return nullptr;
        TreeNode* root = new TreeNode(preorder[low]);
        if (low == high) return root;
        int idx = low + 1;
        while (idx <= high && preorder[idx] < preorder[low]) idx += 1;
        root->left = buildTree(preorder, low + 1, idx - 1);
        root->right = buildTree(preorder, idx, high);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildTree(preorder, 0, preorder.size() - 1);
    }
};