class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int l=0;
        int r=0;
        int n=nums.size();
        int maxlen=0;
        int lenn=0;
        int zeros=0;
        while(r<n){
            
            if(nums[r]==0){
                zeros++;
            }
            if(zeros>k){
                    if(nums[l]==0) zeros--;
                    l++;
            }

            if(zeros<=k){
                lenn=r-l+1;
                maxlen=max(lenn,maxlen);
            }

            r++;
            
        }
        return maxlen;
    }
};