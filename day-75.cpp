/*
  Cheapest Flights Within K Stops


There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

*/

// BFS + also done pruning for optimization
class Solution {
   public:
    unordered_map<int, vector<pair<int, int>>> makeGraph(vector<vector<int>>& flights) {
        unordered_map<int, vector<pair<int, int>>> hashMap;

        for (vector<int>& fly : flights) {
            hashMap[fly[0]].push_back({fly[1], fly[2]});
        }

        return hashMap;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> hashMap = makeGraph(flights);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> flightQueue;

        flightQueue.push({0, src, K + 1});

        int minCost = INT_MAX;

        while (!flightQueue.empty()) {
            vector<int> currFlight = flightQueue.top();
            flightQueue.pop();

            int distance = currFlight[0];
            int currSrc = currFlight[1];
            int currK = currFlight[2];

            if (dst == currSrc) minCost = min(minCost, distance);

            if (currK > 0) {
                for (pair<int, int>& p : hashMap[currSrc]) {
                    if (distance + p.second > minCost) continue;
                    flightQueue.push({distance + p.second, p.first, currK - 1});
                }
            }
        }

        return minCost == INT_MAX ? -1 : minCost;
    }
};