/*
Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true


Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/

// Simple stack solution
class Solution {
   public:
    bool isValid(string s) {
        std::vector<char> stack;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '{')
                stack.push_back('}');
            else if (s[i] == '(')
                stack.push_back(')');
            else if (s[i] == '[')
                stack.push_back(']');
            else {
                if ((stack.empty()) || (s[i] != stack[stack.size() - 1]))
                    return false;
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};