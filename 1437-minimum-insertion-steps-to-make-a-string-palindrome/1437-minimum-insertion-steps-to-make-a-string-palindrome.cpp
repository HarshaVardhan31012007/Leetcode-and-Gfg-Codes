class Solution {
public:
    // int solve(string &s,int i,int j,vector<vector<int>>&dp){
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==s[j])
    //     return dp[i][j]=solve(s,i+1,j-1,dp);
    //     else
    //     return dp[i][j]=1+min(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
    // }
    // int minInsertions(string s) {
    //     vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,-1));
    //     return  solve(s,0,s.length()-1,dp);
    // }


    int solve(string &s){
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<=n-1;j++){
                    if(s[i]==s[j])
                   dp[i][j]=dp[i+1][j-1];
                   else
                   dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
    int minInsertions(string s) {
        return  solve(s);
    }
};