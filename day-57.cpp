/*
  Possible Bipartition

Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

Return true if and only if it is possible to split everyone into two groups in this way.

 

Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Note:

1 <= N <= 2000
0 <= dislikes.length <= 10000
1 <= dislikes[i][j] <= N
dislikes[i][0] < dislikes[i][1]
There does not exist i != j for which dislikes[i] == dislikes[j].

*/


class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& groups, int v, int grpNum) {
      if (groups[v] == -1) groups[v] = grpNum;
      else return groups[v] == grpNum;
      
      for (int n: adj[v]) {
        if (!dfs(adj, groups, n, 1 - grpNum)) return false;
      }
      
      return true;
    }
  
  
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<int> groups(N, -1);
        vector<vector<int>> adjVec(N, vector<int>());
      
      
        for (vector<int>& p : dislikes) {
          adjVec[p[0] - 1].push_back(p[1] - 1);
          adjVec[p[1] - 1].push_back(p[0] - 1);
        }
      
        for (int i = 0; i < N; i++) {
          if (groups[i] == -1 && !dfs(adjVec, groups, i, 0)) return false;
        }
      
        return true;
    }
};

