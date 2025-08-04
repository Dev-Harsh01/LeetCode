class Solution {
public:
    bool canEatAll(const vector<int>& piles, int k, int h) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1LL) / k; // use long long to avoid overflow
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canEatAll(piles, mid, h)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};
