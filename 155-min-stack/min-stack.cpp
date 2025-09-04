class MinStack {
public:
    std::stack<long long> st;
    long long minval;

    MinStack() : minval(0) {}

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minval = val;
            return;
        }
        if (val >= minval) {
            st.push(val);
        } else {
            // encode using previous min
            long long encoded = 2LL * val - minval;
            st.push(encoded);
            minval = val;
        }
    }

    void pop() {
        if (st.empty()) return;
        long long topv = st.top();
        st.pop();
        if (topv < minval) {
            // topv was encoded; recover previous min
            minval = 2LL * minval - topv;
        }
    }

    int top() {
        long long topv = st.top();
        if (topv < minval) {
            // encoded marker; real top is current min
            return (int)minval;
        } else {
            return (int)topv;
        }
    }

    int getMin() {
        return (int)minval;
    }
};
