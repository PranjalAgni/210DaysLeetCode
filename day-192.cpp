/*
Serialize and Deserialize BST

Solution
Serialization is converting a data structure or object into a sequence of bits
so that it can be stored in a file or memory buffer, or transmitted across a
network connection link to be reconstructed later in the same or another
computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is
no restriction on how your serialization/deserialization algorithm should work.
You need to ensure that a binary search tree can be serialized to a string, and
this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.



Example 1:

Input: root = [2,1,3]
Output: [2,1,3]
Example 2:

Input: root = []
Output: []
*/

// Simple seperating "-" by numbers
class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { return encode(root); }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        TreeNode* root = NULL;

        while (getline(ss, item, '-')) root = insert(root, stoi(item));

        return root;
    }

   private:
    string encode(TreeNode* root) {
        if (!root) return "";
        return to_string(root->val) + "-" + encode(root->left) +
               encode(root->right);
    }

    TreeNode* insert(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* temp = new TreeNode(val);
            return temp;
        }

        if (val <= root->val)
            root->left = insert(root->left, val);

        else
            root->right = insert(root->right, val);

        return root;
    }
};