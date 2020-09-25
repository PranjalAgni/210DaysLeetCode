/*

  Largest Number

Given a list of non negative integers, arrange them such that they form the
largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an
integer.

*/

bool compare(string numA, string numB) { return (numA + numB) > (numB + numA); }

// Solved using comparator function
// Beats 92.19 % of cpp submissions.

class Solution {
   public:
    string largestNumber(vector<int>& nums) {
        int N = nums.size();
        vector<string> numsStr(N);

        for (int idx = 0; idx < N; idx++) {
            numsStr[idx] = to_string(nums[idx]);
        }

        sort(numsStr.begin(), numsStr.end(), compare);

        string answer = "";
        for (int idx = 0; idx < N; idx++) answer += numsStr[idx];

        if (answer[0] == '0') return "0";
        return answer;
    }
};