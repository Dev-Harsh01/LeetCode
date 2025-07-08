class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr=0;
        int maxcount=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                curr++;
                maxcount = max(maxcount,curr);

            }
            else{
                curr=0;
            }
        }
        
        return maxcount;
    }
};