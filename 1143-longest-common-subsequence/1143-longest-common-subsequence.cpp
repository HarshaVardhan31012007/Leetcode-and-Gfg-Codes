class Solution {
public:
    // int solve(string &a,string &b,int i,int j,vector<vector<int>>&dp){
    //     if(i>=a.length()||j>=b.length()) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(a[i]==b[j]){
    //         return dp[i][j]=1+solve(a,b,i+1,j+1,dp);
    //     }
    //     else{
    //         return dp[i][j]=max(solve(a,b,i,j+1,dp),solve(a,b,i+1,j,dp));
    //     }
    // }
    // int longestCommonSubsequence(string text1, string text2) {
    //     vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
    //     return solve(text1,text2,0,0,dp);
    // }



    
    int longestCommonSubsequence(string a, string b) {
        vector<vector<int>>dp(a.size()+1,vector<int>(b.size()+1,0));
        for(int i=a.size()-1;i>=0;i--){
            for(int j=b.size()-1;j>=0;j--){
                    if(a[i]==b[j]){
                        dp[i][j]=1+dp[i+1][j+1];
                    }
                    else{
                        dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                    }
            }
        }
        return dp[0][0];
    }
};