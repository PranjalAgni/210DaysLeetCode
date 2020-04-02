/*
  Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 
*/

/*
    Idea: Use XOR
    If odd times: A^A^A = A
    If even times: A^A = 0
    If done with zero: A^0 = A 
*/

// O(N) & O(1)
class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res = res ^ nums[i];
        }

        return res;
    }
};