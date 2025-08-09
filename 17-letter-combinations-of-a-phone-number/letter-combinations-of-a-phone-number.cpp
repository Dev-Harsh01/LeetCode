class Solution {
public:
    void solve(string digits,int index,string comb,string mapping[],vector<string>& ans){
        if(index>=digits.length()){
            ans.push_back(comb);

            return;
        }

        int number=digits[index] - '0';
        string value=mapping[number];

        for(int i=0;i<value.length();i++){
            comb.push_back(value[i]);
            solve(digits,index+1,comb,mapping,ans);
            comb.pop_back();
        }

    }
    
    vector<string> letterCombinations(string digits) {

        vector<string> ans;
        string comb="";
        if(digits.length()==0){
            return ans;
        }
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        solve(digits,0,comb,mapping,ans);

        return ans;
        
        
    }
};