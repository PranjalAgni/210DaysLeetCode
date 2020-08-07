/*
  Vertical Order Traversal of a Binary Tree


Given a binary tree, return the vertical order traversal of its nodes values.

For each node at position (X, Y), its left and right children respectively will
be at positions (X-1, Y-1) and (X+1, Y-1).

Running a vertical line from X = -infinity to X = +infinity, whenever the
vertical line touches some nodes, we report the values of the nodes in order
from top to bottom (decreasing Y coordinates).

If two nodes have the same position, then the value of the node that is reported
first is the value that is smaller.

Return an list of non-empty reports in order of X coordinate.  Every report will
have a list of values of nodes.



Example 1:



Input: [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Without loss of generality, we can assume the root node is at position (0, 0):
Then, the node with value 9 occurs at position (-1, -1);
The nodes with values 3 and 15 occur at positions (0, 0) and (0, -2);
The node with value 20 occurs at position (1, -1);
The node with value 7 occurs at position (2, -2).
Example 2:



Input: [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
The node with value 5 and the node with value 6 have the same position according
to the given scheme. However, in the report "[1,5,6]", the node value of 5 comes
first since 5 is smaller than 6.

*/

// Clean DFS solution + sorting O(N * log(N))
class Solution {
    struct Point {
        int x;
        int y;
        int val;
    };

    struct Comp {
        bool operator()(Point a, Point b) {
            if (a.x == b.x) {
                if (a.y == b.y) return a.val < b.val;
                return a.y > b.y;
            }
            return a.x < b.x;
        }
    };

   public:
    vector<Point> cordinates;

    void dfs(TreeNode* node, int x, int y) {
        cordinates.push_back({x, y, node->val});
        if (node->left) dfs(node->left, x - 1, y - 1);
        if (node->right) dfs(node->right, x + 1, y - 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> answer;

        dfs(root, 0, 0);

        sort(cordinates.begin(), cordinates.end(), Comp());

        for (int idx = 0; idx < cordinates.size();) {
            vector<int> aux;
            do {
                aux.push_back(cordinates[idx++].val);
            } while (idx < cordinates.size() &&
                     cordinates[idx].x == cordinates[idx - 1].x);
            answer.push_back(aux);
        }

        return answer;
    }
};