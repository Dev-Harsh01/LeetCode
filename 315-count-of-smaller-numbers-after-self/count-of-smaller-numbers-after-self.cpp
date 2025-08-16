class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);

        // Step 1: Coordinate compression
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        auto getIndex = [&](int x) {
            return (int)(lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin()) + 1;
        };

        // Fenwick Tree (BIT)
        vector<int> BIT(sorted.size() + 2, 0);

        auto update = [&](int i, int val) {
            for (; i < BIT.size(); i += (i & -i)) {
                BIT[i] += val;
            }
        };

        auto query = [&](int i) {
            int sum = 0;
            for (; i > 0; i -= (i & -i)) {
                sum += BIT[i];
            }
            return sum;
        };

        // Step 2: Process from right to left
        for (int i = n - 1; i >= 0; i--) {
            int idx = getIndex(nums[i]);
            result[i] = query(idx - 1);  // count of smaller elements
            update(idx, 1);              // mark current number
        }

        return result;
    }
};
