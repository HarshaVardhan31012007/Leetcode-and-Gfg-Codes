class Solution {
public:
    void solve(int n,int open,int close,vector<string>&ans,string temp){
        if(open+close==2*n) {
            ans.push_back(temp);
            return;
        }
        if(open==close){
          solve(n,open+1,close,ans,temp+'(');
        }
        else if(open>close){
          solve(n,open,close+1,ans,temp+')');
          if(open!=n)
          solve(n,open+1,close,ans,temp+'(');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        solve(n,0,0,ans,temp);
        return ans;
    }
};