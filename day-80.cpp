/*

  Longest Duplicate Substring


Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

 Example 1:

Input: "banana"
Output: "ana"
Example 2:

Input: "abcd"
Output: ""
 

Note:

2 <= S.length <= 10^5
S consists of lowercase English letters.
*/

// Solved using Rabin Karp Algorithm
class Solution {
   public:
    vector<int> power;
    const int prime = 10000001;

    string rabinKarp(string S, int len) {
        if (len == 0) return "";

        int n = S.length();
        int curr = 0;

        unordered_map<int, vector<int>> hash;

        for (int i = 0; i < len; i++) {
            curr = (curr * 26 + (S[i] - 'a')) % prime;
        }

        hash[curr] = {0};

        for (int i = len; i < n; i++) {
            curr = ((curr - power[len - 1] * (S[i - len] - 'a')) % prime + prime) % prime;
            curr = (curr * 26 + (S[i] - 'a')) % prime;

            if (hash.find(curr) == hash.end()) {
                hash[curr] = {i - len + 1};
            } else {
                for (int index : hash[curr]) {
                    string str = S.substr(i - len + 1, len);

                    if (S.substr(index, len) == str) return S.substr(index, len);
                }

                hash[curr].push_back({i - len + 1});
            }
        }

        return "";
    }
    string longestDupSubstring(string S) {
        int N = S.length();

        int l = 0;
        int r = N - 1;

        power = vector<int>(N);

        power[0] = 1;

        for (int i = 1; i < N; i++) {
            power[i] = (power[i - 1] * 26) % prime;
        }

        string res;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            string curr = rabinKarp(S, mid);

            if (curr.length() > res.length()) {
                res = curr;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};