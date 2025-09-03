class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size();
        int n = t.size();  // Changed variable name from 't' to 'n'
        
        // If lengths are different, they can't be anagrams
        if(m != n) return false;
        
        int arr[26] = {0};  // Initialize array to all zeros
        
        // Count frequency of characters in string s
        for(int i = 0; i < m; i++){
            arr[s[i] - 'a']++;
        }
        
        // Decrement frequency for characters in string t
        for(int i = 0; i < n; i++){
            arr[t[i] - 'a']--;
        }
        
        // Check if all frequencies are zero
        for(int i = 0; i < 26; i++){  // Use 26 instead of arr.length()
            if(arr[i] != 0){
                return false;
            }
        }
        
        return true;
    }
};
