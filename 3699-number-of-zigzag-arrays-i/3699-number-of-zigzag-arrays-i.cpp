class Solution {
public:
    // const int mod=1e9+7;
    // long long NumberOfzigZagArrays(int i,int prev,int flag,int &n,int &l,int &r,vector<vector<vector<int>>>&dp){
    //     if(i>=n) return 1;
    //     if(dp[i][prev][flag]!=-1) return dp[i][prev][flag];
    //     long long ans=0;
    //     if(flag==0){
    //         for(int j=prev+1;j<=r;j++){
    //             ans=(ans+NumberOfzigZagArrays(i+1,j,1,n,l,r,dp))%mod;
    //         }
    //     }
    //     else{
    //         for(int j=prev-1;j>=l;j--){
    //             ans=(ans+NumberOfzigZagArrays(i+1,j,0,n,l,r,dp))%mod;
    //         }
    //     }
    //     return dp[i][prev][flag]=ans;
    // }
    // int zigZagArrays(int n, int l, int r) {
    //     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(r+1,vector<int>(2,-1)));
    //     long long ans=0;
    //     for(int i=l;i<=r;i++){
    //         ans=(ans+NumberOfzigZagArrays(1,i,0,n,l,r,dp))%mod;
    //     }
    //     for(int i=l;i<=r;i++){
    //         ans=(ans+NumberOfzigZagArrays(1,i,1,n,l,r,dp))%mod;
    //     }
    //     return ans;
    // }


    const int mod=1e9+7;
    int zigZagArrays(int n, int l, int r) {
        vector<vector<vector<long long int>>>dp(n+1,vector<vector<long long int>>(2,vector<long long int>(r+2,0)));
        long long ans=0;
        int sum=0;
        for(int i=l,j=r;i<=r&&j>=l;i++,j--){
            sum++;
            dp[n][0][i]=sum;
            dp[n][1][j]=sum;
        }
        for(int i=n-1;i>=1;i--){
           for(int prev=r;prev>=l;prev--){
               dp[i][0][prev]=(dp[i][0][prev]+dp[i+1][1][prev+1])%mod;
               if(i==1)
               ans=(ans+dp[i][0][prev])%mod;
           }
           for(int prev=l;prev<=r;prev++){
               dp[i][1][prev]=(dp[i][1][prev]+dp[i+1][0][prev-1])%mod;
               if(i==1)
               ans=(ans+dp[i][1][prev])%mod;
           }
           long long int sum=0,sum1=0;
           for(int p=l,q=r;p<=r&&q>=l;p++,q--){
                sum+=dp[i][0][p];
                sum1+=dp[i][1][q];
                dp[i][0][p]=sum;
                dp[i][1][q]=sum1;
           }
        }
        return ans;
    }
};