class Solution {
public:
    void findCombinations(vector<int>& candidates, int target, int index, vector<int>& current, vector<vector<int>>& result) {
        // Base case: if target is 0, we found a valid combination
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // If index reaches end or target becomes negative, stop
        if (index >= candidates.size() || target < 0)
            return;

        // Choice 1: Include current candidate (reuse allowed)
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);
            findCombinations(candidates, target - candidates[index], index, current, result);
            current.pop_back(); // backtrack
        }

        // Choice 2: Skip current candidate
        findCombinations(candidates, target, index + 1, current, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(candidates, target, 0, current, result);
        return result;
    }
};
