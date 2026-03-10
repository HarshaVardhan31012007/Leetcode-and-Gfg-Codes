class Solution {
public:
    // const long long mod=1e9+7;
    // long long solve(long long one,long long zero,long long limit,long long prev,vector<vector<vector<long long>>>&dp){
    //     if(one==0&&zero==0) return 1;
    //     if(dp[one][zero][prev]!=-1) return dp[one][zero][prev];
    //     long long ans=0;
    //     if(prev==1){
    //         for(int c=1;c<=min(zero,limit);c++){
    //             ans=(ans+solve(one,zero-c,limit,0,dp))%mod;
    //         }
    //     }
    //     else{
    //         for(int c=1;c<=min(one,limit);c++){
    //             ans=(ans+solve(one-c,zero,limit,1,dp))%mod;
    //         }
    //     }
    //     return dp[one][zero][prev]=ans%mod;
    // }
    // int numberOfStableArrays(int zero, int one, int limit) {
    //     vector<vector<vector<long long>>>dp(one+1,vector<vector<long long>>(zero+1,vector<long long>(2,-1)));
    //     long long ans=0;
    //     for(int c=1;c<=min(zero,limit);c++){
    //         ans=(ans+solve(one,zero-c,limit,0,dp))%mod;
    //     }
    //     for(int c=1;c<=min(one,limit);c++){
    //         ans=(ans+solve(one-c,zero,limit,1,dp))%mod;
    //     }
    //     return ans;
    // }




    // const long long mod=1e9+7;
    // int numberOfStableArrays(int zero1, int one1, int limit) {
    //     vector<vector<vector<long long>>>prefix1(one1+1,vector<vector<long long>>(zero1+1,vector<long long>(2,-1)));
    //     vector<vector<vector<long long>>>prefix2(one1+1,vector<vector<long long>>(zero1+1,vector<long long>(2,-1)));
    //     long long fans=0;
    //     for(int one=0;one<=one1;one++){
    //         for(int zero=0;zero<=zero1;zero++){
    //             for(int prev=0;prev<=1;prev++){
    //                 if(!one&&!zero){
    //                     prefix1[one][zero][prev]=1;
    //                     prefix2[one][zero][prev]=1;
    //                     continue;
    //                 }
    //                 long long ans=0;
    //                 if(prev==1){
    //                     if(min(zero,limit)>=1)
    //                     ans=(ans+prefix1[one][zero-1][!prev]-((zero-min(zero,limit))>0?prefix1[one][zero-min(zero,limit)-1][!prev]:0)+mod)%mod;
    //                 }
    //                 else{
    //                     if(min(one,limit)>=1)
    //                     ans=(ans+prefix2[one-1][zero][!prev]-((one-min(one,limit))>0?prefix2[one-min(one,limit)-1][zero][!prev]:0)+mod)%mod;
    //                 }
    //                 if(one==one1&&zero==zero1)
    //                 fans=(fans+ans)%mod;
    //                 prefix1[one][zero][prev]=(ans+(zero>0?prefix1[one][zero-1][prev]:0))%mod;
    //                 prefix2[one][zero][prev]=(ans+(one>0?prefix2[one-1][zero][prev]:0))%mod;
    //             }
    //         }
    //     }
    //     return fans;
    // }



    const long long mod=1e9+7;
    int numberOfStableArrays(int zero1, int one1, int limit) {
        vector<vector<vector<long long>>>dp(one1+1,vector<vector<long long>>(zero1+1,vector<long long>(2,0)));
        for(int c=0;c<=min(one1,limit);c++)
        dp[c][0][0]=1;
        for(int c=0;c<=min(zero1,limit);c++)
        dp[0][c][1]=1;
        for(int one=1;one<=one1;one++){
            for(int zero=1;zero<=zero1;zero++){
                dp[one][zero][1]=(dp[one][zero-1][1]+dp[one][zero-1][0])%mod;
                if(zero>limit){
                dp[one][zero][1]=(dp[one][zero][1]-dp[one][zero-1-limit][0]+mod)%mod;
                }
                dp[one][zero][0]=(dp[one-1][zero][0]+dp[one-1][zero][1])%mod;
                if(one>limit)//one-1>=k
                dp[one][zero][0]=(dp[one][zero][0]-dp[one-1-limit][zero][1]+mod)%mod;
            }
        }
        return (dp[one1][zero1][0]+dp[one1][zero1][1])%mod;
    }
};