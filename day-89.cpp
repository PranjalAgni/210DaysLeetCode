/*
  Reconstruct Itinerary



Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
One must use all the tickets once and only once.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.

*/

// Simple DFS solution problem is based on Euler path finding since we
// are traversing each edge one
// O(E logE) | Hierholzer's algorithm

class Solution {
   public:
    void dfs(string from, unordered_map<string, vector<string>>& hashMap, vector<string>& result) {
        vector<string>& dest = hashMap[from];

        while (!dest.empty()) {
            string newFrom = dest.back();
            dest.pop_back();
            dfs(newFrom, hashMap, result);
        }

        result.push_back(from);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> hashMap;

        for (vector<string>& vp : tickets) {
            hashMap[vp[0]].push_back(vp[1]);
        }

        for (auto& map : hashMap) {
            sort(map.second.begin(), map.second.end(), greater<string>());
        }

        vector<string> result;
        string from = "JFK";
        dfs(from, hashMap, result);
        reverse(result.begin(), result.end());
        return result;
    }
};