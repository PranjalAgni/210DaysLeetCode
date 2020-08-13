/*
Iterator for Combination

Solution
Design an Iterator class, which has:

A constructor that takes a string characters of sorted distinct lowercase
English letters and a number combinationLength as arguments. A function next()
that returns the next combination of length combinationLength in lexicographical
order. A function hasNext() that returns True if and only if there exists a next
combination.


Example:

CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the
iterator.

iterator.next(); // returns "ab"
iterator.hasNext(); // returns true
iterator.next(); // returns "ac"
iterator.hasNext(); // returns true
iterator.next(); // returns "bc"
iterator.hasNext(); // returns false


Constraints:

1 <= combinationLength <= characters.length <= 15
There will be at most 10^4 function calls per test.
It's guaranteed that all calls of the function next are valid.
*/

// Recursive solution to generate combination, and store in queue
// Time complexity O(N*N)
class CombinationIterator {
    string text;
    queue<string> combinationQue;

   public:
    void getCombination(int start, int length, string txt) {
        if (length == 0) {
            combinationQue.push(txt);
            return;
        }

        for (int idx = start; idx <= text.length() - length; idx++) {
            getCombination(idx + 1, length - 1, txt + text[idx]);
        }
    }

    CombinationIterator(string characters, int combinationLength) {
        text = characters;
        string txt = "";
        getCombination(0, combinationLength, txt);
    }

    string next() {
        string word = combinationQue.front();
        combinationQue.pop();
        return word;
    }

    bool hasNext() { return !combinationQue.empty(); }
};
