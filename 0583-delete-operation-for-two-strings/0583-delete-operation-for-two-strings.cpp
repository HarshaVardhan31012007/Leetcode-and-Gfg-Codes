class Solution {
public:
    // int solve(string &word1,string &word2,int i,int j,vector<vector<int>>&dp){
    //     if(i>=word1.length()) return word2.length()-j;
    //     if(j>=word2.length()) return word1.length()-i;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(word1[i]==word2[j])
    //     return dp[i][j]=solve(word1,word2,i+1,j+1,dp);
    //     else
    //     return dp[i][j]=1+min(solve(word1,word2,i+1,j,dp),solve(word1,word2,i,j+1,dp));
    // }
    // int minDistance(string word1, string word2) {
    //     vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,-1));
    //     return solve(word1,word2,0,0,dp);
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
    int minDistance(string word1, string word2) {
        return word1.length()+word2.length()-2*(longestCommonSubsequence(word1,word2));
    }
};