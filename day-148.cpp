/*
  Fizz Buzz


Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for
the multiples of five output “Buzz”. For numbers which are multiples of both
three and five output “FizzBuzz”.


Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
*/

// Simple O(N) time & memory solution
class Solution {
   public:
    vector<string> fizzBuzz(int n) {
        vector<string> answers(n);

        for (int num = 1; num <= n; num++) {
            if (num % 3 == 0 && num % 5 == 0)
                answers[num - 1] = "FizzBuzz";
            else if (num % 3 == 0)
                answers[num - 1] = "Fizz";
            else if (num % 5 == 0)
                answers[num - 1] = "Buzz";
            else
                answers[num - 1] = to_string(num);
        }

        return answers;
    }
};