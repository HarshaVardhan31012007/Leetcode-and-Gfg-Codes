class Solution {
public:
    vector<int> countBits(int n) {
    //    vector<int>dp(n+1,-1);
    //    dp[0]=0;
    //    if(n>=1)
    //    dp[1]=1;
    //    for(int i=2;i<n+1;i++){
    //     if(i%2==0)
    //     dp[i]=dp[i/2];
    //     else
    //     dp[i]=1+dp[i/2];
    //    }
    //    return dp;


    //  vector<int>dp(n+1,-1);
    //    dp[0]=0;
    //    for(int i=1;i<n+1;i++){
    //     if(i&1)
    //     dp[i]=1+dp[i>>1];
    //     else
    //     dp[i]=dp[i>>1];
    //    }
    //    return dp;


     vector<int>dp(n+1,0);
    for(int i=1;i<n+1;i++){
      dp[i]=1+dp[i&i-1];
    }
       return dp;
    }
};