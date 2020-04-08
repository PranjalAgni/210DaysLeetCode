/*
Question: Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.
*/
class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            len = len + 1;
            temp = temp->next;
        }
        int mid = len / 2;
        temp = head;
        while (mid-- > 0) {
            temp = temp->next;
        }
        return temp;
    }
};