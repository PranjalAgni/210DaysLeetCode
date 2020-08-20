/*
  Reorder List


Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be
changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

*/

// Simple O(N) solution. Updated values in list
class Solution {
   public:
    void reorderList(ListNode* head) {
        vector<int> nodeVals;
        ListNode* temp = head;

        while (temp != NULL) {
            nodeVals.push_back(temp->val);
            temp = temp->next;
        }

        temp = head;

        int start = 0;
        int end = nodeVals.size() - 1;
        bool isFront = true;

        while (temp != NULL) {
            temp->val = nodeVals[isFront ? start : end];
            temp = temp->next;
            if (isFront)
                start += 1;
            else
                end -= 1;
            isFront = !isFront;
        }
    }
};