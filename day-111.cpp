/*
  Remove Linked List Elements


Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
*/

// Simple solution manipulating linked list in place O(N) & O(1)
class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        while (head != NULL && head->val == val) {
            head = head->next;
        }

        ListNode* customHead = head;
        ListNode* prev = NULL;

        while (customHead != NULL && customHead->next != NULL) {
            if (customHead->next->val == val) {
                customHead->next = customHead->next->next;
            } else {
                customHead = customHead->next;
            }
        }

        return head;
    }
};