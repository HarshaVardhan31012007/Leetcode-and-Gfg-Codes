class Solution {
public:
    // int solve(string &s1,string &s2,int i,int j,vector<vector<int>>&dp){
    //   if(i>=s1.size()||j>=s2.size()) return 0;
    //   if(dp[i][j]!=-1)
    //   return dp[i][j];
    //   if(s1[i]==s2[j])
    //   return dp[i][j]=s1[i]+solve(s1,s2,i+1,j+1,dp);
    //   else
    //   return dp[i][j]=max(solve(s1,s2,i+1,j,dp),solve(s1,s2,i,j+1,dp));
    // }
    // int minimumDeleteSum(string s1, string s2) {
    //     int sum=0;
    //     for(auto &i:s1)
    //     sum=sum+i;
    //     for(auto &j:s2)
    //     sum=sum+j;
    //     int m=s1.size();int n=s2.size();
    //     vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    //     return sum-2*solve(s1,s2,0,0,dp);
    // }



    // int solve(string &s1,string &s2){
    //     int m=s1.size();int n=s2.size();
    //     vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    //     for(int i=m-1;i>=0;i--){
    //         for(int j=n-1;j>=0;j--){
    //             if(s1[i]==s2[j])
    //             dp[i][j]=s1[i]+dp[i+1][j+1];
    //             else
    //             dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
    //         }
    //     }
    //     return dp[0][0];
    // }

    int solve(string &s1,string &s2){
        int m=s1.size();int n=s2.size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(s1[i]==s2[j])
                curr[j]=s1[i]+next[j+1];
                else
                curr[j]=max(next[j],curr[j+1]);
            }
            next=curr;
        }
        return next[0];
    }
    int minimumDeleteSum(string s1, string s2) {
        int sum=0;
        for(auto &i:s1)
        sum=sum+i;
        for(auto &j:s2)
        sum=sum+j;
        return sum-2*solve(s1,s2);
    }
};