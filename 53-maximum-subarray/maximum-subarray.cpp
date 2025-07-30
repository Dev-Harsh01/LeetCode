class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum =0;
        int max_sum = INT_MIN;
        for(int i=0;i<nums.size();i++){
            currsum += nums[i];
            max_sum = max(currsum,max_sum);
            if(currsum<0){
                currsum=0;
            }
        }

        return max_sum;
    }
};