/*
  Maximum XOR of Two Numbers in an Array


Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.

*/

// Solved using Trie, O(N) approach
class Trie {
   public:
    Trie() { next[0] = next[1] = nullptr; }

    ~Trie() {
        if (next[0]) {
            delete next[0];
        }

        if (next[1]) {
            delete next[1];
        }
    }

    void insert(int n) {
        Trie* cur = this;

        for (int i = 31; i >= 0; --i) {
            if (n & (1 << i)) {
                if (!cur->next[1]) {
                    cur->next[1] = new Trie();
                }
                cur = cur->next[1];
            } else {
                if (!cur->next[0]) {
                    cur->next[0] = new Trie();
                }
                cur = cur->next[0];
            }
        }

        cur->val = n;
    }

    int findOpposite(int n) {
        Trie* cur = this;

        for (int i = 31; i >= 0; --i) {
            if (n & (1 << i)) {
                if (cur->next[0]) {
                    cur = cur->next[0];
                } else {
                    cur = cur->next[1];
                }
            } else {
                if (cur->next[1]) {
                    cur = cur->next[1];
                } else {
                    cur = cur->next[0];
                }
            }
        }

        return cur->val;
    }

   private:
    int val;
    Trie* next[2];
};

class Solution {
   public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;

        Trie root;

        for (auto n : nums) {
            root.insert(n);
        }

        for (auto n : nums) {
            ans = max(ans, n ^ root.findOpposite(n));
        }

        return ans;
    }
};