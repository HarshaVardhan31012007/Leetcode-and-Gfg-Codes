class Solution {
public:
    // int solve(string &s,int i,int j,vector<vector<int>>&dp){
    //     if(i>=j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int ans=0;
    //     if(s[i]==s[j])
    //     ans=solve(s,i+1,j-1,dp);
    //     else
    //     ans=1+min(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
    //     return dp[i][j]=ans;
    // }
    // int minInsertions(string s) {
    //     vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,-1));
    //     return solve(s,0,s.length()-1,dp);
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
    int longestPalindromeSubseq(string s) {
        string temp=s;
        reverse(s.begin(),s.end());
        return longestCommonSubsequence(s,temp);
    }
    int minInsertions(string s) {
        int lps=longestPalindromeSubseq(s);
        return s.length()-lps;
    }
};