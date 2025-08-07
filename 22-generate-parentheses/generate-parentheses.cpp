class Solution {
public:
    void generate(vector<string>& s,int n,int open,int close, string a){
        if (a.length() == 2 * n){
            s.push_back(a);
            return;
        }
        
        if(open<n){
            generate(s,n,open+1,close,a+"(");
        }

        if(close<open){
             generate(s,n,open,close+1,a+")");
        }
    }
    
    vector<string> generateParenthesis(int n) {

        vector<string> s;

        generate(s,n,0,0,"");
        return s;
       

    }
};