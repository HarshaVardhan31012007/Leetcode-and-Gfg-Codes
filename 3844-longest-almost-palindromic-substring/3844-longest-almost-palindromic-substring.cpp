class Solution {
public:
    // int solve(string &s,int i,int j,int flag,vector<vector<vector<int>>>&dp){
    //     if(i>j){
    //         if(flag==0) return 0;
    //         else return INT_MIN;
    //     }
    //     if(i==j){
    //         if(flag==0) return 1;
    //         else if(flag==1) return 0;
    //         else
    //             return 0;
    //     }
    //     if(dp[i][j][flag]!=1e9) return dp[i][j][flag];
    //     if(flag==2){
    //         int curr=INT_MIN;
    //         int ans=INT_MIN;
    //         if(s[i]==s[j]){
    //             int t=2+solve(s,i+1,j-1,1,dp);
    //             if(t>=0&&t>curr){
    //                 ans=(j-i+1);curr=t;
    //             }
    //         }
    //             int t=solve(s,i,j,1,dp);
    //             if(t>=0&&t>curr){
    //                 ans=(j-i+1);curr=t;
    //             }
    //         int t1=solve(s,i,j-1,2,dp);
    //         if(t1>ans){
    //             ans=t1;
    //         }
    //         int t2=solve(s,i+1,j,2,dp);
    //         if(t2>ans){
    //             ans=t2;
    //         }
    //         return dp[i][j][flag]=ans;
    //     }
    //     else if(flag==0){
    //         if(s[i]==s[j])
    //             return dp[i][j][flag]=2+solve(s,i+1,j-1,0,dp);
    //         else
    //              return dp[i][j][flag]=INT_MIN;
    //     }
    //     else{
    //         int curr=INT_MIN;
    //         if(s[i]==s[j]){
    //             curr=max(curr,2+solve(s,i+1,j-1,1,dp));
    //         }
    //         if(flag){
    //              curr=max(curr,solve(s,i+1,j,0,dp));
    //              curr=max(curr,solve(s,i,j-1,0,dp));
    //         }
    //         return dp[i][j][flag]=curr;
    //     }
    // }
    // int almostPalindromic(string s) {
    //    int n=s.length();
    //    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(3,1e9)));
    //    return solve(s,0,n-1,2,dp);
    // }



    
    // int almostPalindromic(string s) {
    //    int n=s.length();
    //    static int dp[2501][2501][3];
    //    for(int i=0;i<=n;i++){
    //        for(int flag=0;flag<=2;flag++){
    //            if(flag==0)
    //             dp[i][i][0]=1;
    //             else
    //             dp[i][i][flag]=0;
    //        }
    //    }
    //    for(int i=0;i<=n;i++){
    //        for(int j=i-1;j>=0;j--){
    //         dp[i][j][0]=0;
    //        }
    //    }
    //    for(int i=n-1;i>=0;i--){
    //        for(int j=i+1;j<n;j++){
    //            for(int flag=0;flag<=2;flag++){
    //                            if(flag==2){
    //                     int curr=INT_MIN;
    //                     int ans=INT_MIN;
    //                     if(s[i]==s[j]){
    //                         int t=2+dp[i+1][j-1][1];
    //                         if(t>=0&&t>curr){
    //                             ans=(j-i+1);curr=t;
    //                         }
    //                     }
    //                         int t=dp[i][j][1];
    //                         if(t>=0&&t>curr){
    //                             ans=(j-i+1);curr=t;
    //                         }
    //                     int t1=dp[i][j-1][2];
    //                     if(t1>ans){
    //                         ans=t1;
    //                     }
    //                     int t2=dp[i+1][j][2];
    //                     if(t2>ans){
    //                         ans=t2;
    //                     }
    //                     dp[i][j][flag]=ans;
    //                 }
    //                 else if(flag==0){
    //                     if(s[i]==s[j])
    //                         dp[i][j][flag]=2+dp[i+1][j-1][0];
    //                     else
    //                          dp[i][j][flag]=INT_MIN;
    //                 }
    //                 else{
    //                     int curr=INT_MIN;
    //                     if(s[i]==s[j]){
    //                         curr=max(curr,2+dp[i+1][j-1][1]);
    //                     }
    //                     if(flag){
    //                          curr=max(curr,dp[i+1][j][0]);
    //                          curr=max(curr,dp[i][j-1][0]);
    //                     }
    //                     dp[i][j][flag]=curr;
    //                 }
    //            }
    //        }
    //    }
    //     return dp[0][n-1][2];
    // }



    // void check(string &str,int i,int j,int &ans){
    //     while(i>=0&&j<str.length()&&str[i]==str[j]){
    //         i--;j++;
    //     }
    //     ans=max(ans,j-i-1);
    // }
    // int almostPalindromic(string str) {
    //     int n=str.length();
    //     int ans=2;
    //     for(int i=0;i<n;i++){
    //         int s=i;int e=i;
    //         while(s>=0&&e<n&&str[s]==str[e]){
    //             s--;e++;
    //         }
    //         ans=max(ans,e-s-1);
    //         if(s>=0)
    //         check(str,s-1,e,ans);
    //         if(e<n)
    //         check(str,s,e+1,ans);
    //         s=i;e=i+1;
    //         while(s>=0&&e<n&&str[s]==str[e]){
    //             s--;e++;
    //         }
    //         ans=max(ans,e-s-1);
    //         if(s>=0)
    //         check(str,s-1,e,ans);
    //         if(e<n)
    //         check(str,s,e+1,ans);
    //     }
    //     return ans;
    // }




    int solve(string &s,int i,int j,int dp[][2501]){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j]; 
        if(s[i]==s[j]) return dp[i][j]=solve(s,i+1,j-1,dp);
        else
        return dp[i][j]=1+min(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
    }
    int almostPalindromic(string str) {
        int n=str.length();
        int ans=2;
        int dp[n+1][2501];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
           for(int j=i;j<n;j++){
              if(solve(str,i,j,dp)<=1){
                  ans=max(ans,j-i+1);
              }
           }
        }
        return ans;
    }
};