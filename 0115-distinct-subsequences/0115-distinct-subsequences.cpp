class Solution {
public:
    // int solve(string &s,string &t,int i,int j,vector<vector<int>>&dp){
    //    if(j>=t.size())
    //      return 1;
    //    if(i>=s.size()) 
    //    return 0;
    //    if(dp[i][j]!=-1)
    //    return dp[i][j];
    //    int l=0;
    //    if(s[i]==t[j])
    //    l=solve(s,t,i+1,j+1,dp);
    //    int r=solve(s,t,i+1,j,dp);
    //    return dp[i][j]=l+r;
    // }
    // int numDistinct(string s, string t) {
    //     int m=s.size();int n=t.size();
    //     vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    //     return solve(s,t,0,0,dp);
    // }


    // int solve(string &s,string &t){
    //    int m=s.size();int n=t.size();
    //     vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    //     for(int i=0;i<=m;i++)
    //     dp[i][n]=1;
    //     for(int i=m-1;i>=0;i--){
    //         for(int j=n-1;j>=0;j--){
    //                 long long ans=0;
    //                 if(s[i]==t[j])
    //                 ans+=dp[i+1][j+1];
    //                 ans+=dp[i+1][j];
    //                  dp[i][j]=ans;
    //         }
    //     }
    //     return dp[0][0];
    // }

    //  int solve(string &s,string &t){
    //    int m=s.size();int n=t.size();
    //     vector<int>curr(n+1,0);
    //     vector<int>next(n+1,0);
    //     curr[n]=next[n]=1;
    //     for(int i=m-1;i>=0;i--){
    //         for(int j=n-1;j>=0;j--){
    //                 long long ans=0;
    //                 if(s[i]==t[j])
    //                 ans+=next[j+1];
    //                 ans+=next[j];
    //                 curr[j]=ans;
    //         }
    //         next=curr;
    //     }
    //     return curr[0];
    // }


    //  int solve(string &s,string &t){
    //    int m=s.size();int n=t.size();
    //     vector<int>curr(n+1,0);
    //     curr[n]=1;
    //     for(int i=m-1;i>=0;i--){
    //         for(int j=0;j<=n-1;j++){
    //                 long long ans=0;
    //                 if(s[i]==t[j])
    //                 ans+=curr[j+1];
    //                 ans+=curr[j];
    //                 curr[j]=ans;
    //         }
    //     }
    //     return curr[0];
    // }
    // int numDistinct(string s, string t) {
    //     return solve(s,t);
    // }


     int solve(string &s,string &t){
       int m=s.size();int n=t.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++)
        dp[i][n]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                    long long int l=0;
                    if(s[i]==t[j])
                    l=dp[i+1][j+1];
                    long long int r=dp[i+1][j];
                     dp[i][j]=l+r;
            }
        }
        return dp[0][0];
    }
    int numDistinct(string s, string t) {
        return solve(s,t);
    }
};