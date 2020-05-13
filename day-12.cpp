/*
Question: We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

Example 1:
Input: [2,7,4,1,8,1]
Output: 1
*/

class Solution {
   public:
    int lastStoneWeight(vector<int>& stones) {
        int start = stones.size() - 1;
        int stonesCrushed = 0;
        sort(stones.begin(), stones.end());
        while (stonesCrushed < (stones.size() - 1)) {
            int lar = stones[start];
            int sLar = stones[start - 1];
            int diff = lar - sLar;
            if (lar == sLar) {
                stonesCrushed += 2;
                diff = -1;
            } else {
                stonesCrushed += 1;
            }

            stones[start] = diff;
            stones[start - 1] = -1;
            sort(stones.begin(), stones.end());
        }

        return stones[start] > 0 ? stones[start] : 0;
    }
};