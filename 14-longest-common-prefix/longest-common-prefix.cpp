class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string str1=strs[0];
        string str2=strs[strs.size()-1];
        string ans="";
        int i=0;
        while(i < str1.length() && i < str2.length()){
            if(str1[i]==str2[i]){
                ans.push_back(str1[i]);
                i++;
            }
            else{
                break;
            }
        }

        return ans;
        
    }
};