class Solution {
public:
    bool solve(string &a,string &b,int i,int j,vector<vector<int>>&dp){
        if(i>=a.length()&&j>=b.length()) return true;
        if(i>=a.length()){
            for(int k=j;k<b.length();k++){
                if(b[k]!='*')
                return false;
            }
            return true;
        }
        if(j>=b.length()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=false;
        if(b[j]=='?'||a[i]==b[j]){
            ans=solve(a,b,i+1,j+1,dp);
        }
        else if(b[j]=='*'){
            ans=solve(a,b,i+1,j,dp)||solve(a,b,i,j+1,dp);
        }
        return dp[i][j]=ans;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,-1));
        return solve(s,p,0,0,dp);
    }
};