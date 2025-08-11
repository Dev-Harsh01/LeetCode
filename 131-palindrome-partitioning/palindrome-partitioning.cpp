class Solution {
public:
    bool ispalindrome(string a){
        int left=0;
        int right=a.length()-1;

        while(left<right){
            if(a[left] != a[right]){
                return false;
                break;
            }

            left++;
            right--;
        }

        return true;
        
    }
    
    void solve(string s,vector<string> &a,vector<vector<string>>& ans){
        if(s.size()==0){
            ans.push_back(a);
            return;
        }
        for(int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);
            if(ispalindrome(part)){
                a.push_back(part);
                solve(s.substr(i+1),a,ans);
                a.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> a;
        vector<vector<string>> ans;
        solve(s,a,ans);
        return ans;
        
    }
};