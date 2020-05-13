/*
Question: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

class MinStack {
   public:
    stack<pair<int, int>> tinyStack;
    int min;
    MinStack() {
        min = INT_MAX;
    }

    void push(int x) {
        if (x < min) min = x;
        tinyStack.push(make_pair(x, min));
    }

    void pop() {
        tinyStack.pop();
        if (tinyStack.size() == 0)
            min = INT_MAX;
        else
            min = tinyStack.top().second;
    }

    int top() {
        return tinyStack.top().first;
    }

    int getMin() {
        return tinyStack.top().second;
    }
};