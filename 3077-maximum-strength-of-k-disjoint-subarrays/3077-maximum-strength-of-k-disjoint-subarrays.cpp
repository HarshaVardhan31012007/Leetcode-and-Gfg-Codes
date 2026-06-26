class Solution {
public:
    // int k1;
    // long long solve(vector<int>&nums,int i,int n,int k){
    //     if(k==0) return 0;
    //     if(i>=n) return LLONG_MIN;
    //     long long ans=LLONG_MIN;
    //     long long sign=((k&1)?1:-1);
    //     long long sum=0;
    //     for(int j=i;j<n;j++){
    //         sum+=nums[j];
    //         long long reccall=solve(nums,j+1,n,k-1);
    //         if(reccall!=LLONG_MIN)
    //         ans=max(ans,sign*k*sum+reccall);
    //         if(k1==k){
    //             long long rec1=solve(nums,j+1,n,k);
    //             ans=max(ans,rec1);
    //         }
    //     }
    //     return ans;
    // }
    // long long maximumStrength(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     k1=k;
    //     return solve(nums,0,n,k);
    // }



   
    
    // long long maximumStrength(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     vector<vector<long long>>dp(n+1,vector<long long>(k+1,LLONG_MIN));
    //     for(int i=0;i<=n;i++) 
    //     dp[i][0]=0;
    //     for(int k1=1;k1<=k;k1++){
    //         for(int i=n-1;i>=0;i--){
    //             long long ans=LLONG_MIN;
    //             long long sign=((k1&1)?1:-1);
    //             long long sum=0;
    //             for(int j=i;j<n;j++){
    //                 sum+=nums[j];
    //                 long long reccall=dp[j+1][k1-1];
    //                 if(reccall!=LLONG_MIN)
    //                 ans=max(ans,sign*k1*sum+reccall);
    //                 if(k1==k){
    //                     long long rec1=dp[j+1][k1];
    //                     ans=max(ans,rec1);
    //                 }
    //             }
    //             dp[i][k1]=ans;
    //         }
    //     }
    //     return dp[0][k];
    // }



    long long maximumStrength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(k+1,LLONG_MIN));
        vector<long long>prefixsum(n+1,0);
        long long int sum=0;
        for(int i=0;i<=n;i++){
           if(i<n){
                sum+=nums[i];
                prefixsum[i+1]=sum;
           }
           dp[i][0]=0;
        }
        for(int k1=1;k1<=k;k1++){
            long long ans=LLONG_MIN;
            for(int i=n-1;i>=0;i--){
                long long curr=LLONG_MIN;
                long long sign=((k1&1)?1:-1);
                long long reccall=dp[i+1][k1-1];
                if(reccall!=LLONG_MIN)
                ans=max(ans,sign*k1*prefixsum[i+1]+reccall);
                if(k1==k){
                    long long rec1=dp[i+1][k1];
                    curr=max(curr,rec1);
                }
                if(ans!=LLONG_MIN){
                   curr=max(curr,-sign*k1*prefixsum[i]+ans);
                }
                dp[i][k1]=max(dp[i][k1],curr);
            }
        }
        return dp[0][k];
    }



    // vector<vector<vector<long long>>>dp;
    // long long solve(int i,vector<int>&nums,int n,long long k,bool started){
    //     if(k==0) return 0;
    //     if(i>=n) return -1e14;
    //     if(dp[i][k][started]!=-1) return dp[i][k][started];
    //     long long take=LLONG_MIN,not_take=LLONG_MIN;
    //     if(!started){
    //        not_take=solve(i+1,nums,n,k,false);
    //     }
    //     if(k%2==0){
    //         take=max(take,-k*nums[i]+solve(i+1,nums,n,k-1,true));
    //         take=max(take,-k*nums[i]+solve(i+1,nums,n,k,true));
    //     }
    //     else{
    //         take=max(take,k*nums[i]+solve(i+1,nums,n,k-1,true));
    //         take=max(take,k*nums[i]+solve(i+1,nums,n,k,true));
    //     }
    //     return dp[i][k][started]=max(take,not_take);
    // }
    // long long maximumStrength(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     dp.assign(n+1,vector<vector<long long>>(k+1,vector<long long>(2,-1)));
    //     return solve(0,nums,n,k,false);
    // }
};