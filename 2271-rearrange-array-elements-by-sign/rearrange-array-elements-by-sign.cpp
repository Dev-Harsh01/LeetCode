class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive={};
         vector<int> negative={};
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                positive.push_back(nums[i]);
            }
            else{
                negative.push_back(nums[i]);
            }
        }
        vector<int> result;
          for(int j = 0; j < positive.size(); j++) {
            result.push_back(positive[j]);
            result.push_back(negative[j]);
        }      
        return result; 
    }
};