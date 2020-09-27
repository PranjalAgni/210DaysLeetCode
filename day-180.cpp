/*
  Evaluate Division


You are given equations in the format A / B = k, where A and B are variables
represented as strings, and k is a real number (floating-point number). Given
some queries, return the answers. If the answer does not exist, return -1.0.

The input is always valid. You may assume that evaluating the queries will
result in no division by zero and there is no contradiction.



Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries =
[["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]] Output:
[6.00000,0.50000,-1.00000,1.00000,-1.00000] Explanation: Given: a / b = 2.0, b /
c = 3.0 queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
Example 2:

Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0],
queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]] Output:
[3.75000,0.40000,5.00000,0.20000] Example 3:

Input: equations = [["a","b"]], values = [0.5], queries =
[["a","b"],["b","a"],["a","c"],["x","y"]] Output:
[0.50000,2.00000,-1.00000,-1.00000]


Constraints:

1 <= equations.length <= 20
equations[i].length == 2
1 <= equations[i][0], equations[i][1] <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= queries[i][0], queries[i][1] <= 5
equations[i][0], equations[i][1], queries[i][0], queries[i][1] consist of lower
case English letters and digits.

*/

// Solved using dfs
class Solution {
   public:
    void dfs(unordered_map<string, vector<pair<string, double>>> mp,
             string source, string destination,
             unordered_map<string, int>& visited, double& ans, double temp) {
        if (visited.count(source)) return;

        visited[source] = 1;

        if (source == destination) {
            ans = temp;
            return;
        }

        for (auto x : mp[source]) {
            dfs(mp, x.first, destination, visited, ans, temp * x.second);
        }

        return;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> mp;

        for (int i = 0; i < equations.size(); i++) {
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        vector<double> v;
        for (int i = 0; i < queries.size(); i++) {
            string s = queries[i][0];
            string d = queries[i][1];
            double ans = -1;
            unordered_map<string, int> visited;
            if (mp.count(s)) dfs(mp, s, d, visited, ans, 1.0);
            v.push_back(ans);
        }

        return v;
    }
};