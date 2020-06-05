/*
  Random Pick with Weight


Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.

*/

/* Tricky problem to understand, but simple implementation: Idea is to
 make prefix sum for the array, and then generate random number between
 (1 to sum), after that we just need to do binary search

 For example:
 Index          0 1 2 3
 I/p            1 2 5 6
 prefix-sum     1 3 8 14
 elts(1-sum)    1 2 3 4 5 6 7 8 9 10 11 12 13 14 (1 to sum)

 If we map index elements to elts array we notice using Input array
 1st element of index (0) has 1 number i.e 1
 2nd element of index (1) has 2 numbers i.e 2 3
 3rd element of index (2) has 5 numbers i.e {4..8}
 4th element of index (3) has 6 numbers i.e {9..14}

 Now generate random number in range(0-14) suppose 5
 Now for 5 we need to search in prefix-sum element which is nextGreater than 5 so doing a binary search will give 8, now as the 
 number 8 comes in 2nd index of array just return that index.
*/
class Solution {
   public:
    vector<int> weights;
    Solution(vector<int>& w) {
        weights = vector<int>(w.size(), 0);
        weights[0] = w[0];
        for (int i = 1; i < w.size(); i++) {
            weights[i] = weights[i - 1] + w[i];
        }
    }

    int pickIndex() {
        int sum = weights[weights.size() - 1];
        int target = rand() % (sum);
        int low = 0;
        int high = weights.size() - 1;
        int idx = -1;
        while (low <= high) {
            int mid = (low + (high - low) / 2);
            if (target < weights[mid]) {
                idx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return idx;
    }
};
