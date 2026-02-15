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




    int almostPalindromic(string s) {
       int n=s.length();
       static int dp[2505][2505][3];
       for(int i=0;i<=n;i++){
           for(int flag=0;flag<=2;flag++){
               if(flag==0)
                dp[i][i][0]=1;
                else
                dp[i][i][flag]=0;
           }
       }
       for(int i=0;i<=n;i++){
           for(int j=i-1;j>=0;j--){
            dp[i][j][0]=0;
           }
       }
       for(int i=n-1;i>=0;i--){
           for(int j=i+1;j<n;j++){
               for(int flag=0;flag<=2;flag++){
                               if(flag==2){
                        int curr=INT_MIN;
                        int ans=INT_MIN;
                        if(s[i]==s[j]){
                            int t=2+dp[i+1][j-1][1];
                            if(t>=0&&t>curr){
                                ans=(j-i+1);curr=t;
                            }
                        }
                            int t=dp[i][j][1];
                            if(t>=0&&t>curr){
                                ans=(j-i+1);curr=t;
                            }
                        int t1=dp[i][j-1][2];
                        if(t1>ans){
                            ans=t1;
                        }
                        int t2=dp[i+1][j][2];
                        if(t2>ans){
                            ans=t2;
                        }
                        dp[i][j][flag]=ans;
                    }
                    else if(flag==0){
                        if(s[i]==s[j])
                            dp[i][j][flag]=2+dp[i+1][j-1][0];
                        else
                             dp[i][j][flag]=INT_MIN;
                    }
                    else{
                        int curr=INT_MIN;
                        if(s[i]==s[j]){
                            curr=max(curr,2+dp[i+1][j-1][1]);
                        }
                        if(flag){
                             curr=max(curr,dp[i+1][j][0]);
                             curr=max(curr,dp[i][j-1][0]);
                        }
                        dp[i][j][flag]=curr;
                    }
               }
           }
       }
        return dp[0][n-1][2];
    }
};