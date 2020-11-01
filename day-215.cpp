/*
  Convert Binary Number in a Linked List to Integer


Given head which is a reference node to a singly-linked list. The value of each
node in the linked list is either 0 or 1. The linked list holds the binary
representation of a number.

Return the decimal value of the number in the linked list.



Example 1:


Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
Example 2:

Input: head = [0]
Output: 0
Example 3:

Input: head = [1]
Output: 1
Example 4:

Input: head = [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0]
Output: 18880
Example 5:

Input: head = [0,0]
Output: 0


Constraints:

The Linked List is not empty.
Number of nodes will not exceed 30.
Each node's value is either 0 or 1.

*/

// Simple linear time solution using vectors and maths
class Solution {
   public:
    int getDecimalValue(ListNode* head) {
        vector<int> digits;
        while (head != NULL) {
            digits.push_back(head->val);
            head = head->next;
        }

        int len = digits.size();
        int pos = 0;
        int answer = 0;
        for (int idx = len - 1; idx >= 0; idx--, pos++) {
            answer += digits[idx] * pow(2, pos);
        }

        return answer;
    }
};