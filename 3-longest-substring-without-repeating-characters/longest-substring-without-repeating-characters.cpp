class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1); // initialize all with -1

        int r = 0, l = 0, maxlen = 0;
        int n = s.size();

        while (r < n) {
            // if character has been seen before and is inside the current window
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;  // move left pointer
            }

            hash[s[r]] = r;  // update last seen index of character
            maxlen = max(maxlen, r - l + 1); // update max length
            r++;
        }

        return maxlen;
    }
};
