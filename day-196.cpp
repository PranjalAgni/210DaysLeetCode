/*
  Sort List


Given the head of a linked list, return the list after sorting it in ascending
order.

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e.
constant space)?



Example 1:


Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
Example 3:

Input: head = []
Output: []


Constraints:

The number of nodes in the list is in the range [0, 5 * 104].
-105 <= Node.val <= 105

*/

// Simple O(NlogN) and O(N) solution
class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        vector<int> vals;
        ListNode* temp = head;

        while (temp != NULL) {
            vals.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;
        sort(vals.begin(), vals.end());
        int idx = 0;
        while (temp != NULL) {
            temp->val = vals[idx];
            temp = temp->next;
            idx += 1;
        }

        return head;
    }
};