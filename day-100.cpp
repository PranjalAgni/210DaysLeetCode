/*
  Maximum Width of Binary Tree


Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).


Note: Answer will in the range of 32-bit signed integer.
*/

// Used BFS to solve this problem. 100 days completed today :)
class Solution {
   public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        int result = 1;

        queue<pair<TreeNode*, int>> nodesQueue;

        nodesQueue.push({root, 0});

        while (!nodesQueue.empty()) {
            int N = nodesQueue.size();

            int start = nodesQueue.front().second;

            int end = nodesQueue.back().second;

            result = max(result, end - start + 1);

            for (int i = 0; i < N; i++) {
                pair<TreeNode*, int> currPair = nodesQueue.front();
                int idx = currPair.second - start;
                nodesQueue.pop();

                if (currPair.first->left) nodesQueue.push({currPair.first->left, 2 * idx + 1});
                if (currPair.first->right) nodesQueue.push({currPair.first->right, 2 * idx + 2});
            }
        }
        return result;
    }
};