/*
Merge k Sorted Lists

Solution
You are given an array of k linked-lists lists, each linked-list is sorted in
ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length won't exceed 10^4.
*/

// Recursive solution to merge the list
class Solution {
   public:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* head = l1->val <= l2->val ? l1 : l2;
        head->next = l1->val <= l2->val ? merge2Lists(l1->next, l2)
                                        : merge2Lists(l1, l2->next);
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;

        ListNode* head = lists[0];

        for (int i = 1; i < lists.size(); i++)
            head = merge2Lists(head, lists[i]);

        return head;
    }
};