class Solution {
public:
    void solve(vector<int>& candidates,vector<int>& nums,int target,int index,vector<vector<int>>& ans){
        if(target==0){
            ans.push_back({nums});
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue; // skip duplicates
            if (candidates[i] > target) break; // no need to continue
            
            nums.push_back(candidates[i]);
            solve(candidates, nums, target - candidates[i], i + 1, ans); // i+1 because each can be used once
            nums.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> nums;
        solve(candidates,nums,target,0,ans);
        return ans;
    }
};