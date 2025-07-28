class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    // Constructor
    MinStack() {}

    // Push value onto stack
    void push(int val) {
        mainStack.push(val);
        // If minStack is empty or val is <= top of minStack, push to minStack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    // Pop value from stack
    void pop() {
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        mainStack.pop();
    }

    // Get top value
    int top() {
        return mainStack.top();
    }

    // Get current minimum value
    int getMin() {
        return minStack.top();
    }
};