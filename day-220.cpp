class Solution {
   public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1e6;
        int ans;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int sum = 0;
            for (auto num : nums) {
                sum += ceil((float)(num) / (float)(mid));
            }
            if (sum <= threshold) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};