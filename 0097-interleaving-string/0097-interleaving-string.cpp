class Solution {
public:

    // bool solve(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<vector<int>>>&dp){
    //    if(i==s1.size()&&j==s2.size()&&k==s3.size()) return 1;
    //    if(dp[i][j][k]!=-1) return dp[i][j][k];
    //    bool ans=0;
    //    if(j<s2.size()&&s2[j]==s3[k])
    //    ans=ans||solve(s1,s2,s3,i,j+1,k+1,dp);
    //    if(i<s1.size()&&s1[i]==s3[k])
    //    ans=ans||solve(s1,s2,s3,i+1,j,k+1,dp);
    //    return dp[i][j][k]=ans;
    // }
    // bool isInterleave(string s1, string s2, string s3) {
    //     int m=s1.size();int n=s2.size();int p=s3.size();
    //     vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(p+1,-1)));
    //     return solve(s1,s2,s3,0,0,0,dp);
    // }


    //  bool solve(string &s1,string &s2,string &s3){
    //      int m=s1.size();int n=s2.size();int p=s3.size();
    //     vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(p+1,-1)));
    //     if(m+n!=p) return false;
    //     dp[m][n][p]=1;
    //     for(int i=m;i>=0;i--){
    //         for(int j=n;j>=0;j--){
    //             for(int k=p;k>=0;k--){
    //                 if(i==m&&j==n&&k==p) continue;
    //                 bool ans=0;
    //                 if(j<s2.size()&&s2[j]==s3[k])
    //                 ans=ans||dp[i][j+1][k+1];
    //                 if(i<s1.size()&&s1[i]==s3[k])
    //                 ans=ans||dp[i+1][j][k+1];
    //                 dp[i][j][k]=ans;
    //             }
    //         }
    //     }
    //     return dp[0][0][0];
    // }




     bool solve(string &s1,string &s2,string &s3,int i,int j,vector<vector<int>>&dp){
       if(i==s1.size()&&j==s2.size()) return 1;
       if(dp[i][j]!=-1) return dp[i][j];
       bool ans=0;
       if(j<s2.size()&&s2[j]==s3[i+j])
       ans=ans||solve(s1,s2,s3,i,j+1,dp);
       if(i<s1.size()&&s1[i]==s3[i+j])
       ans=ans||solve(s1,s2,s3,i+1,j,dp);
       return dp[i][j]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size();int n=s2.size();int p=s3.size();
        if(m+n!=p) return false;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(s1,s2,s3,0,0,dp);
    }
    //  bool solve(string &s1,string &s2,string &s3){
    //      int m=s1.size();int n=s2.size();int p=s3.size();
    //     vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    //     if(m+n!=p) return false;
    //     dp[m][n]=1;
    //     for(int i=m;i>=0;i--){
    //         for(int j=n;j>=0;j--){
    //                 if(i==m&&j==n) continue;
    //                 bool ans=0;
    //                 if(j<s2.size()&&s2[j]==s3[i+j])
    //                 ans=ans||dp[i][j+1];
    //                 if(i<s1.size()&&s1[i]==s3[i+j])
    //                 ans=ans||dp[i+1][j];
    //                 dp[i][j]=ans;
    //         }
    //     }
    //     return dp[0][0];
    // }
    // bool isInterleave(string s1, string s2, string s3) {
    //     return solve(s1,s2,s3);
    // }
};