class MinStack {
public:
    stack<pair<int,int>> s;  // {value, min till now}

    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val, val});
        }
        else{
            int minval = min(val, s.top().second);
            s.push({val, minval});  // ✅ push both value and updated min
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
