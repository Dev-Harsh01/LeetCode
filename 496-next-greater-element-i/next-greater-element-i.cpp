class Solution {
public:
    void solve(vector<int>& nums1, vector<int>& nums2, int i, vector<int>& ans) {
        if (i >= nums1.size()) return;

        // find nums1[i] in nums2
        int j = 0;
        while (j < nums2.size() && nums2[j] != nums1[i]) j++;

        int nextGreater = -1;
        for (int k = j + 1; k < nums2.size(); k++) {
            if (nums2[k] > nums1[i]) {
                nextGreater = nums2[k];
                break;
            }
        }
        ans.push_back(nextGreater);

        solve(nums1, nums2, i + 1, ans);
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        solve(nums1,nums2,0,ans);

        return ans;
        
    }
};