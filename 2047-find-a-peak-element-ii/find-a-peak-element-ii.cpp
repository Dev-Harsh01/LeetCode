class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int lo = 0, hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int r = 0;
            for (int i = 1; i < m; ++i)
                if (mat[i][mid] > mat[r][mid])
                    r = i;

            int leftVal = (mid - 1 >= 0) ? mat[r][mid - 1] : INT_MIN;
            int rightVal = (mid + 1 < n) ? mat[r][mid + 1] : INT_MIN;
            int cur = mat[r][mid];

            if (cur > leftVal && cur > rightVal)
                return {r, mid};
            else if (leftVal > cur)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return {-1, -1}; // should not happen
    }
};
