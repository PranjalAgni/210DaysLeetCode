/*
  Basic Calculator II


Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators
and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.


*/

// String scan solution
class Solution {
   public:
    int calculate(string s) {
        istringstream iss('+' + s + '+');
        int total = 0;
        int leftOperand = 0;
        int rightOperand = 0;
        char op;
        while (iss >> op) {
            if (op == '+' || op == '-') {
                total += leftOperand;
                iss >> leftOperand;
                leftOperand *= (op == '+' ? 1 : -1);
            } else {
                iss >> rightOperand;
                if (op == '*')
                    leftOperand *= rightOperand;
                else
                    leftOperand /= rightOperand;
            }
        }
        return total;
    }
};