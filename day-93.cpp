/*
  Binary Tree Level Order Traversal II


Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

*/

// Simple Queue based solution
class Solution {
   public:
    void levelOrderTraversal(TreeNode* root, unordered_map<int, vector<int>>& hashMap, int key) {
        if (root == NULL) return;

        hashMap[key].push_back(root->val);

        levelOrderTraversal(root->left, hashMap, key + 1);
        levelOrderTraversal(root->right, hashMap, key + 1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;

        if (root == NULL) return {};

        queue<TreeNode*> nodes;

        nodes.push(root);

        while (!nodes.empty()) {
            int N = nodes.size();

            vector<int> temp(N);

            for (int i = 0; i < N; i++) {
                TreeNode* currNode = nodes.front();
                nodes.pop();

                temp[i] = currNode->val;

                if (currNode->left) nodes.push(currNode->left);
                if (currNode->right) nodes.push(currNode->right);
            }

            ans.push_back(temp);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    // Slow solution using hashMap

    //     vector<vector<int>> levelOrderBottom(TreeNode* root) {
    //         unordered_map<int,vector<int>> hashMap;
    //         levelOrderTraversal(root, hashMap, 0);

    //         vector<vector<int>> ans;

    //         int idx = 0;
    //         while (true) {
    //             if (hashMap.count(idx)) {
    //                 ans.push_back(hashMap[idx]);
    //             } else {
    //                 break;
    //             }

    //             idx += 1;
    //         }

    //         reverse(ans.begin(), ans.end());

    //         return ans;
    //     }
};