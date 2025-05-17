class Solution {
public:
    // int solve(string &s,int i,int j,vector<vector<int>>&dp){
    //     if(i>j) return 0;
    //     if(i==j) return 1;
    //     if(dp[i][j]!=-1)
    //     return dp[i][j];
    //     if(s[i]==s[j])
    //     return dp[i][j]=2+solve(s,i+1,j-1,dp);
    //     else
    //     return dp[i][j]=max(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
    // }
    // int longestPalindromeSubseq(string s) {
    //     int n=s.length();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     return solve(s,0,n-1,dp);
    // }


    // int solve(string &s){
    //      int n=s.length();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //     for(int i=0;i<n+1;i++)
    //     dp[i][i]=1;
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=i+1;j<n;j++){
    //            if(s[i]==s[j])
    //            dp[i][j]=2+dp[i+1][j-1];
    //            else
    //            dp[i][j]=max(dp[i+1][j],dp[i][j-1]); 
    //         }
    //     }
    //     return dp[0][n-1];
    // }
    // int longestPalindromeSubseq(string s) {
    //     return solve(s);
    // }


    // int solve(string &s){
    //      int n=s.length();
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //     for(int i=0;i<n+1;i++)
    //     dp[i][i]=1;
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=i+1;j<n;j++){
    //            if(s[i]==s[j])
    //            dp[i][j]=2+dp[i+1][j-1];
    //            else
    //            dp[i][j]=max(dp[i+1][j],dp[i][j-1]); 
    //         }
    //     }
    //     return dp[0][n-1];
    // }
    // int longestPalindromeSubseq(string s) {
    //     return solve(s);
    // }

       

    //    int solve(string &s,string &p,int i,int j,vector<vector<int>>&dp){
    //     if(i==s.size()||j==p.size()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==p[j])
    //     return dp[i][j]=1+solve(s,p,i+1,j+1,dp);
    //     else
    //     return dp[i][j]=max(solve(s,p,i+1,j,dp),solve(s,p,i,j+1,dp));
    //    }
    //   int longestPalindromeSubseq(string s) {
    //     string p=s;int n=s.size();
    //     reverse(p.begin(),p.end());
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     return solve(s,p,0,0,dp);
    // }



    // int solve(string &s){
    //     string p=s;int n=s.size();
    //     reverse(p.begin(),p.end());
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //     for(int i=n-1;i>=0;i--){
    //         for(int j=n-1;j>=0;j--){
    //            if(s[i]==p[j])
    //            dp[i][j]=1+dp[i+1][j+1];
    //            else
    //            dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
    //         }
    //     }
    //     return dp[0][0];
    //    }
    //   int longestPalindromeSubseq(string s) {
    //     return solve(s);
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
};