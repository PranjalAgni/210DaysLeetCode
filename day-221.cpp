/*
  Add Two Numbers II


You are given two non-empty linked lists representing two non-negative integers.
The most significant digit comes first and each of their nodes contain a single
digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists
is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7

*/

// Solution using strings to add list reverse order
class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string a, b;
        ListNode* result = nullptr;
        while (l1) {
            a.push_back(l1->val + '0');
            l1 = l1->next;
        }

        while (l2) {
            b.push_back(l2->val + '0');
            l2 = l2->next;
        }

        int l = a.size() - 1, r = b.size() - 1, carry = 0;

        while (l >= 0 || r >= 0 || carry == 1) {
            int c = (l >= 0 ? a[l--] - '0' : 0) + (r >= 0 ? b[r--] - '0' : 0) +
                    carry;
            ListNode* temp = new ListNode(c % 10);
            temp->next = result;
            result = temp;
            carry = c / 10;
        }
        return result;
    }
};