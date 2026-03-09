class Solution {
public:
    // const long long mod=1e9+7;
    // long long solve(long long one,long long zero,long long limit,long long prev,long long prevcount,vector<vector<vector<vector<long long>>>>&dp){
    //     if(one==0&&zero==0) return 1;
    //     if(prev!=-1&&dp[one][zero][prevcount][prev]!=-1) return dp[one][zero][prevcount][prev];
    //     long long ans=0;
    //     if(prev==-1){
    //         ans=(ans+solve(one-1,zero,limit,1,1,dp))%mod;
    //         ans=(ans+solve(one,zero-1,limit,0,1,dp))%mod;
    //     }
    //     else{
    //         if(prev==1){
    //             if(one>0&&prevcount+1<=limit){
    //                 ans=(ans+solve(one-1,zero,limit,1,prevcount+1,dp))%mod;
    //             }
    //             if(zero>0){
    //                 ans=(ans+solve(one,zero-1,limit,0,1,dp))%mod;
    //             }
    //         }
    //         else{
    //             if(zero>0&&prevcount+1<=limit){
    //                 ans=(ans+solve(one,zero-1,limit,0,prevcount+1,dp))%mod;
    //             }
    //             if(one>0){
    //                 ans=(ans+solve(one-1,zero,limit,1,1,dp))%mod;
    //             }
    //         }
    //     }
    //     if(prev!=-1)
    //     return dp[one][zero][prevcount][prev]=ans%mod;
    //     else
    //     return ans;
    // }
    // int numberOfStableArrays(int zero, int one, int limit) {
    //     vector<vector<vector<vector<long long>>>>dp(one+2,vector<vector<vector<long long>>>(zero+2,vector<vector<long long>>(limit+2,vector<long long>(2,-1))));
    //     return solve(one,zero,limit,-1,-1,dp);
    // }




    const long long mod=1e9+7;
    long long solve(long long one,long long zero,long long limit,long long prev,vector<vector<vector<long long>>>&dp){
        if(one==0&&zero==0) return 1;
        if(dp[one][zero][prev]!=-1) return dp[one][zero][prev];
        long long ans=0;
        if(prev==1){
            for(int c=1;c<=min(zero,limit);c++){
                ans=(ans+solve(one,zero-c,limit,0,dp))%mod;
            }
        }
        else{
            for(int c=1;c<=min(one,limit);c++){
                ans=(ans+solve(one-c,zero,limit,1,dp))%mod;
            }
        }
        return dp[one][zero][prev]=ans%mod;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>>dp(one+1,vector<vector<long long>>(zero+1,vector<long long>(2,-1)));
        long long ans=0;
        for(int c=1;c<=min(zero,limit);c++){
            ans=(ans+solve(one,zero-c,limit,0,dp))%mod;
        }
        for(int c=1;c<=min(one,limit);c++){
            ans=(ans+solve(one-c,zero,limit,1,dp))%mod;
        }
        return ans;
    }
};