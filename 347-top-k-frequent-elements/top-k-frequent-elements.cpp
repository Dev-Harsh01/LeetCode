class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mpp;
        for(auto num : nums){
            mpp[num]++;
        }
        int n = nums.size();
        vector<vector<int>> temp(n+1);
        for(auto it:mpp){
            temp[it.second].push_back(it.first);
        }
        int cnt = 0;
        vector<int> ans;

        for(int i = n ; i >= 0 ; i--){
            if(cnt == k) break;
            if(temp[i].size() != 0){
                for(auto it:temp[i]) {
                    ans.push_back(it);
                    cnt++;
                }
            }
        }

        return ans;
    }
};