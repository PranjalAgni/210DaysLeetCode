/*
  Binary Tree Zigzag Level Order Traversal


Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

// BFS approach using deque
class Solution {
   public:
    void storeNodesInQueue(deque<TreeNode*>& currLevelNodes, TreeNode* nodeA, TreeNode* nodeB) {
        if (nodeA) currLevelNodes.push_front(nodeA);
        if (nodeB) currLevelNodes.push_front(nodeB);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return {};

        vector<vector<int>> answer;
        deque<TreeNode*> nodes;

        nodes.push_back(root);
        bool isReverseLevel = true;

        while (!nodes.empty()) {
            vector<int> currLevel;
            deque<TreeNode*> currLevelNodes;
            int N = nodes.size();

            for (int idx = 0; idx < N; idx++) {
                TreeNode* currNode = nodes.front();
                nodes.pop_front();
                currLevel.push_back(currNode->val);

                if (isReverseLevel) {
                    storeNodesInQueue(currLevelNodes, currNode->left, currNode->right);
                } else {
                    storeNodesInQueue(currLevelNodes, currNode->right, currNode->left);
                }
            }

            isReverseLevel = !isReverseLevel;

            nodes.insert(nodes.end(), currLevelNodes.begin(), currLevelNodes.end());
            answer.push_back(currLevel);
        }

        return answer;
    }
};