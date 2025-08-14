class StockSpanner {
public:
    stack<pair<int,int>> st; // {price, span}
    
    StockSpanner() { }
    
    int next(int price) {
        int span = 1; // current day
        
        // Merge with all previous days having price <= current price
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        
        st.push({price, span});
        return span;
    }
};
