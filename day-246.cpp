/*
Linked List Random Node

Solution
Given a singly linked list, return a random node's value from the linked list.
Each node must have the same probability of being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you?
Could you solve this efficiently without using extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should
have equal probability of returning. solution.getRandom();

*/

// Simple vector + rand() solution
class Solution {
   public:
    vector<int> elements;
    Solution(ListNode* head) {
        elements = vector<int>();
        ListNode* temp = head;
        while (temp != NULL) {
            elements.push_back(temp->val);
            temp = temp->next;
        }
    }

    int getRandom() {
        int N = elements.size();
        int idx = (rand() % N);
        return elements[idx];
    }
};
