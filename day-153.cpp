/*
  Delete Node in a BST


Given a root node reference of a BST and a key, delete the node with the given
key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7

 */

// Delete a node from BST in O(height of tree)

class Solution {
   public:
    TreeNode* minValueNode(TreeNode* root) {
        TreeNode* current = root;
        while (current && current->left != NULL) current = current->left;
        return current;
    }

    TreeNode* deleteNodeHelper(TreeNode* root, int& key) {
        if (root == NULL) return root;

        if (key < root->val)
            root->left = deleteNodeHelper(root->left, key);
        else if (key > root->val)
            root->right = deleteNodeHelper(root->right, key);
        else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                root = NULL;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                root = NULL;
                return temp;
            }

            TreeNode* temp = minValueNode(root->right);

            root->val = temp->val;
            root->right = deleteNodeHelper(root->right, temp->val);
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteNodeHelper(root, key);
    }
};