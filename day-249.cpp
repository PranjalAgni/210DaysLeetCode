/*
Can Place Flowers

Solution
You have a long flowerbed in which some of the plots are planted, and some are
not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and
1 means not empty, and an integer n, return if n new flowers can be planted in
the flowerbed without violating the no-adjacent-flowers rule.



Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false


Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length
*/

// Simple elegant for loop solution
class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int N = flowerbed.size();
        for (int idx = 0; idx < N; idx++) {
            if (flowerbed[idx] == 1) continue;
            if ((idx == 0 || flowerbed[idx - 1] == 0) &&
                (idx == N - 1 || flowerbed[idx + 1] == 0)) {
                flowerbed[idx] = 1;
                n -= 1;
            }
        }

        return n <= 0;
    }
};