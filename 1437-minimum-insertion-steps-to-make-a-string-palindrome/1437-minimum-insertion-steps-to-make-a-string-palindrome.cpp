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


    // int solve(string &s){
    //     int n=s.length();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=i+1;j<=n-1;j++){
    //                 if(s[i]==s[j])
    //                dp[i][j]=dp[i+1][j-1];
    //                else
    //                dp[i][j]=1+min(dp[i+1][j],dp[i][j-1]);
    //         }
    //     }
    //     return dp[0][n-1];
    // }
    // int minInsertions(string s) {
    //     return  solve(s);
    // }



     int solve(string &s){
        string p=s;int n=s.size();
        reverse(p.begin(),p.end());
       vector<int>curr(n+1,0);
       vector<int>next(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
               if(s[i]==p[j])
               curr[j]=1+next[j+1];
               else
               curr[j]=max(next[j],curr[j+1]);
            }
            next=curr;
        }
        return curr[0];
       }
      int longestPalindromeSubseq(string s) {
        return solve(s);
    }
    int minInsertions(string s) {
        return  s.length()-longestPalindromeSubseq(s);
    }

};