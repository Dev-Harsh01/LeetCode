class Solution {
public:
    void printsum(vector<int>& nums,vector<int>& ans,int i,vector<vector<int>>& finall){
        if(i==nums.size()){
            finall.push_back({ans});
            return;
        }

        ans.push_back(nums[i]);
        printsum(nums,ans,i+1,finall);

        ans.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }
        printsum(nums,ans,idx,finall);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> finall;
        vector<int> ans;

        printsum(nums,ans,0,finall);

        return finall;


        
    }
};