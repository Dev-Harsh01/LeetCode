class Solution {
public:
    bool check(vector<int>& nums) {
        int pivot = 0;
        int n = nums.size();
        
        // Find the pivot where the order decreases
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                pivot = i + 1;
                break;
            }
        }
        
        // If no pivot found, the array is already sorted (valid rotation)
        if (pivot == 0) {
            return true;
        }
        
        // Check if the remaining elements after pivot are sorted
        // and the last element is <= the first element
        bool isSorted = true;
        for (int i = pivot; i < n - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                isSorted = false;
                break;
            }
        }
        
        return isSorted && (nums.back() <= nums[0]);
    }
};