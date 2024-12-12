class Solution {
public:
    void solve(vector<string>&ans,int n,int open,int close,string &output){
        if(open+close==2*n){
            ans.push_back(output);
            return;
        }
        if(open<n){
            output.push_back('(');
            solve(ans,n,open+1,close,output);
            output.pop_back();
        }
         if(close<open){
            output.push_back(')');
            solve(ans,n,open,close+1,output);
            output.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output="";
        solve(ans,n,0,0,output);
        return ans;
    }
};