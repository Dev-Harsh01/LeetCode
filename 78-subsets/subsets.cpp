class Solution {
public:
    void printsubset(vector<int>& arr,vector<int>& ans,int i,vector<vector<int>>& allsubset){
        if(i==arr.size()){
            allsubset.push_back({ans});
            return;
        }
        ans.push_back(arr[i]);
        printsubset(arr,ans,i+1,allsubset);

        ans.pop_back();

        printsubset(arr,ans,i+1,allsubset);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubset;
        vector<int> ans;
        printsubset(nums,ans,0,allsubset);

        return allsubset;



        
    }
};