class Solution {
public:
    // bool solve(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<vector<int>>>&dp){
    //     if(k>=s3.size()&&j>=s2.length()&&i>=s1.length()) return true;
    //     if(dp[i][j][k]!=-1) return dp[i][j][k];
    //     bool ans=false;
    //     if(i<s1.length()&&k<s3.length()&&s1[i]==s3[k]){
    //         ans=ans||solve(s1,s2,s3,i+1,j,k+1,dp);
    //     }
    //     if(j<s2.length()&&k<s3.length()&&s2[j]==s3[k]){
    //         ans=ans||solve(s1,s2,s3,i,j+1,k+1,dp);
    //     }
    //     return dp[i][j][k]=ans;
    // }
    // bool isInterleave(string s1, string s2, string s3) {
    //     vector<vector<vector<int>>>dp(s1.length()+1,vector<vector<int>>(s2.length()+1,vector<int>(s3.length()+1,-1)));
    //     return solve(s1,s2,s3,0,0,0,dp);
    // }



    //  bool solve(string &s1,string &s2,string &s3,int i,int j,vector<vector<int>>&dp){
    //     if(i+j>=s3.length()&&j>=s2.length()&&i>=s1.length()) return true;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     bool ans=false;
    //     if(i<s1.length()&&i+j<s3.length()&&s1[i]==s3[i+j]){
    //         ans=ans||solve(s1,s2,s3,i+1,j,dp);
    //     }
    //     if(j<s2.length()&&i+j<s3.length()&&s2[j]==s3[i+j]){
    //         ans=ans||solve(s1,s2,s3,i,j+1,dp);
    //     }
    //     return dp[i][j]=ans;
    // }
    // bool isInterleave(string s1, string s2, string s3) {
    //     vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
    //     return solve(s1,s2,s3,0,0,dp);
    // }
    


    //  bool solve(string &s1,string &s2,string &s3,int i,int j,vector<vector<int>>&dp){
    //     if(j>=s2.length()&&i>=s1.length()) return true;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     bool ans=false;
    //     if(i<s1.length()&&i+j<s3.length()&&s1[i]==s3[i+j]){
    //         ans=ans||solve(s1,s2,s3,i+1,j,dp);
    //     }
    //     if(j<s2.length()&&i+j<s3.length()&&s2[j]==s3[i+j]){
    //         ans=ans||solve(s1,s2,s3,i,j+1,dp);
    //     }
    //     return dp[i][j]=ans;
    // }
    // bool isInterleave(string s1, string s2, string s3) {
    //     if(s3.length()!=s1.length()+s2.length()) return false;
    //     vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
    //     return solve(s1,s2,s3,0,0,dp);
    // }




    
    // bool isInterleave(string s1, string s2, string s3) {
    //     if(s3.length()!=(s1.length()+s2.length())) return false;
    //     vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
    //     dp[s1.length()][s2.length()]=1;
    //     for(int i=s1.length();i>=0;i--){
    //         for(int j=s2.length();j>=0;j--){
    //             if(i==s1.length()&&j==s2.length()) continue;
    //             bool ans=false;
    //             if(i<s1.length()&&s1[i]==s3[i+j])
    //             ans=ans||dp[i+1][j];
    //             if(j<s2.length()&&s2[j]==s3[i+j])
    //             ans=ans||dp[i][j+1];
    //             dp[i][j]=ans;
    //         }
    //     }
    //     return dp[0][0];
    // }




    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length()!=(s1.length()+s2.length())) return false;
        vector<int>curr(s2.length()+1,0);
        vector<int>next(s2.length()+1,0);
        curr[s2.length()]=1;
        for(int i=s1.length();i>=0;i--){
            for(int j=s2.length();j>=0;j--){
                if(i==s1.length()&&j==s2.length()) continue;
                bool ans=false;
                if(i<s1.length()&&s1[i]==s3[i+j])
                ans=ans||next[j];
                if(j<s2.length()&&s2[j]==s3[i+j])
                ans=ans||curr[j+1];
                curr[j]=ans;
            }
            next=curr;
        }
        return curr[0];
    }
};