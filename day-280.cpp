/*
Remove Duplicates from Sorted List II

Solution
Given the head of a sorted linked list, delete all nodes that have duplicate
numbers, leaving only distinct numbers from the original list. Return the linked
list sorted as well.



Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]


Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

*/

// Simple O(N) solution
class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head or !head->next) return head;
        if (head->val == head->next->val) {
            int val = head->val;
            while (head and head->val == val) head = head->next;
            return deleteDuplicates(head);
        } else {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};