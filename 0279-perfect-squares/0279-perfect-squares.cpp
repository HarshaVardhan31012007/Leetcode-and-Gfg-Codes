class Solution {
public:
    //  int solve(int n,vector<int>&num,vector<int>&dp){
    //     if(n==0)
    //     return 0;
    //     if(dp[n]!=-1)
    //     return dp[n];
    //     int ans=INT_MAX;
    //     for(auto &each:num){
    //         if(each<=n){
    //         int t=solve(n-each,num,dp);
    //         if(t!=INT_MAX)
    //         ans=min(ans,1+t);
    //         }
    //     }
    //     return dp[n]=ans;
    // }
    // int numSquares(int n) {
    //     double a=sqrt(n);
    //     if(a==(int)a) return 1;
    //     vector<int>num;
    //     for(int i=1;i<n;i++){
    //         if(sqrt(i)==(int)sqrt(i))
    //         num.push_back(i);
    //     }
    //     vector<int>dp(n+1,-1);
    //    return solve(n,num,dp);
    // }


    //  int solve(int n,vector<int>&num){
    //     vector<int>dp(n+1,INT_MAX);
    //     dp[0]=0;
    //     for(int i=1;i<=n;i++){
    //         int ans=INT_MAX;
    //         for(auto &each:num){
    //         if(each<=i){
    //         if(dp[i-each]!=INT_MAX)
    //         ans=min(ans,1+dp[i-each]);
    //         }
    //     }
    //     dp[i]=ans;
    //     }
    //     return dp[n];
    // }
    // int numSquares(int n) {
    //     double a=sqrt(n);
    //     if(a==(int)a) return 1;
    //     vector<int>num;
    //     for(int i=1;i<n;i++){
    //         if(sqrt(i)==(int)sqrt(i))
    //         num.push_back(i);
    //     }
    //    return solve(n,num);
    // }


    // int solve(int n,vector<int>&dp){
    //     if(n==0) return 0;
    //     if(dp[n]!=-1)
    //     return dp[n];
    //     int end=sqrt(n);
    //     int i=1;
    //     int ans=INT_MAX;
    //     while(i<=end){
    //         ans=min(ans,1+solve(n-(i*i),dp));
    //         i++;
    //     }
    //     return dp[n]=ans;
    // }
    // int numSquares(int n){
    //     vector<int>dp(n+1,-1);
    //     return solve(n,dp);
    // }

    int solve(int n){
       vector<int>dp(n+1,-1);
       dp[0]=0;
       for(int i=1;i<=n;i++){
        int j=1;
        int end=sqrt(i);
        int ans=INT_MAX;
        while(j<=end){
           ans=min(ans,1+dp[i-j*j]);
           j++;
        }
        dp[i]=ans;
       }
       return dp[n];
    }
    int numSquares(int n){
        return solve(n);
    }
};