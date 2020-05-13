/*
Question: Given an integer array arr, count element x such that x + 1 is also in arr.
If there're duplicates in arr, count them seperately.

EXAMPLE:
Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.

Input: arr = [1,1,2,2]
Output: 2
Explanation: Two 1s are counted cause 2 is in arr.
*/

class Solution {
   public:
    int countElements(vector<int>& arr) {
        map<int, int> hashMap;
        for (int i = 0; i < arr.size(); i++) {
            hashMap[arr[i]] += 1;
        }

        int cnt = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (hashMap[arr[i] + 1] > 0) {
                cnt++;
            }
        }

        return cnt;
    }
};