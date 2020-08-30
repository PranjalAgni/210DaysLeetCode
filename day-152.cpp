/*
  Largest Component Size by Common Factor


Given a non-empty array of unique positive integers A, consider the following
graph:

There are A.length nodes, labelled A[0] to A[A.length - 1];
There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a
common factor greater than 1. Return the size of the largest connected component
in the graph.



Example 1:

Input: [4,6,15,35]
Output: 4

Example 2:

Input: [20,50,9,63]
Output: 2

Example 3:

Input: [2,3,6,7,4,12,21,39]
Output: 8

Note:

1 <= A.length <= 20000
1 <= A[i] <= 100000
*/

class Solution {
   public:
    vector<int> parent;
    vector<int> rank;
    int getParent(int x) {
        if (parent[x] == -1) return x;
        return parent[x] = getParent(parent[x]);
    }
    void unionn(int x, int y) {
        int parX = getParent(x);
        int parY = getParent(y);
        if (parX == parY) return;
        if (rank[parX] >= rank[parY]) {
            rank[parX] += rank[parY];
            parent[parY] = parX;
        } else {
            rank[parY] += rank[parX];
            parent[parX] = parY;
        }
    }

    int largestComponentSize(vector<int>& A) {
        int ret = 0;
        int n = A.size();
        parent = vector<int>(n, -1);
        rank = vector<int>(n, 1);
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            int x = A[i];
            for (int j = 2; j * j <= x; j++) {
                if (x % j == 0) {
                    if (m.count(j)) {
                        unionn(m[j], i);
                    } else {
                        m[j] = i;
                    }
                    if (m.count(x / j)) {
                        unionn(m[x / j], i);
                    } else {
                        m[x / j] = i;
                    }
                }
            }
            if (m.count(x)) {
                unionn(m[x], i);
            } else {
                m[x] = i;
            }
            ret = max(ret, rank[getParent(i)]);
        }
        return ret;
    }
};