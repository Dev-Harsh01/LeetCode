class Solution {
public:
    // Helper function to find the first occurrence of the target using binary search
    int findFirstOccurrence(const int* nums, int size, int target) {
        int index = -1; // Initialize with -1, indicating not found
        int low = 0;
        int high = size - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Calculate mid to prevent potential overflow

            if (nums[mid] == target) {
                index = mid;     // Found a potential first occurrence
                high = mid - 1;  // Try to find an earlier one in the left half
            } else if (nums[mid] < target) {
                low = mid + 1;   // Target is in the right half
            } else { // nums[mid] > target
                high = mid - 1;  // Target is in the left half
            }
        }
        return index;
    }

    // Helper function to find the last occurrence of the target using binary search
    int findLastOccurrence(const int* nums, int size, int target) {
        int index = -1; // Initialize with -1, indicating not found
        int low = 0;
        int high = size - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Calculate mid to prevent potential overflow

            if (nums[mid] == target) {
                index = mid;    // Found a potential last occurrence
                low = mid + 1;  // Try to find a later one in the right half
            } else if (nums[mid] < target) {
                low = mid + 1;  // Target is in the right half
            } else { // nums[mid] > target
                high = mid - 1; // Target is in the left half
            }
        }
        return index;
    }

    // Main function to search for the range
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        // We still need to return std::vector<int> as per the problem signature.
        // But we will populate it using our custom binary search results.
        std::vector<int> result;
        result.push_back(-1); // Initialize first occurrence to -1
        result.push_back(-1); // Initialize last occurrence to -1

        if (nums.empty()) {
            return result;
        }

        // Pass pointer to the beginning of the vector's data and its size
        // This avoids using std::vector's indexing in the helper functions directly,
        // treating it more like a C-style array.
        int* nums_ptr = nums.data();
        int size = nums.size();

        result[0] = findFirstOccurrence(nums_ptr, size, target);
        result[1] = findLastOccurrence(nums_ptr, size, target);

        return result;
    }
};