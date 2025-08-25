class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        long long left = 1;
        long long right = x;
        long long result = 1;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            // Check if mid*mid is the square root
            if (mid * mid == x) {
                return mid;
            } 
            
            // If mid*mid is less than x, it could be a potential answer. 
            // We store it and try to find a larger one.
            else if (mid * mid < x) {
                result = mid;
                left = mid + 1;
            } 
            
            // If mid*mid is greater than x, the square root must be in the lower half.
            else {
                right = mid - 1;
            }
        }
        return result;
    }
};