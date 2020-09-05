/*
  All Elements in Two Binary Search Trees


Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending
order.



Example 1:


Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]
Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]
Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]
Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]
Example 5:


Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]


Constraints:

Each tree has at most 5000 nodes.
Each node's value is between [-10^5, 10^5].
 */

// Inorder traversal + merging sorted array beats 98.91% of cpp submissions.
// Time & Memory complexity O(N)
class Solution {
   public:
    void inorderTraversal(TreeNode* root, vector<int>& nodes) {
        if (root == NULL) return;
        inorderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        inorderTraversal(root->right, nodes);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        // below 3 lines improve execution time drastically (75% -> 98.91%)
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> nodes1;
        vector<int> nodes2;
        inorderTraversal(root1, nodes1);
        inorderTraversal(root2, nodes2);
        int N1 = nodes1.size();
        int N2 = nodes2.size();
        int start1 = 0;
        int start2 = 0;

        vector<int> answer;
        while (start1 < N1 && start2 < N2) {
            if (nodes1[start1] < nodes2[start2]) {
                answer.push_back(nodes1[start1]);
                start1 += 1;
            } else {
                answer.push_back(nodes2[start2]);
                start2 += 1;
            }
        }

        while (start1 < N1) {
            answer.push_back(nodes1[start1]);
            start1 += 1;
        }

        while (start2 < N2) {
            answer.push_back(nodes2[start2]);
            start2 += 1;
        }

        return answer;
    }
};