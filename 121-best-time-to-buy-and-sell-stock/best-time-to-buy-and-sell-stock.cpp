class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        int max=0;
        int buy=prices[0];

        for(int i=0;i<n;i++){
            int curr =prices[i]-buy;

            if(curr>max){
                max=curr;
            }
            if(prices[i]<buy){
                buy=prices[i];
            }
        }
        return max;
    }
};