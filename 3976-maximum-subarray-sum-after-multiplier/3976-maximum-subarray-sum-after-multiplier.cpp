class Solution {
public:
    // long long solve(int i,int started,vector<int>&nums,int n,int k,vector<vector<long long>>&dp,long long &ans){
    //     if(i>=n) return 0;
    //     if(dp[i][started]!=-1) return dp[i][started]; 
    //     if(!started){
    //         long long reccall=solve(i+1,0,nums,n,k,dp,ans);
    //         long long reccall1=solve(i+1,1,nums,n,k,dp,ans);
    //         long long reccall2=solve(i+1,2,nums,n,k,dp,ans);
    //         long long current1;
    //         if(nums[i]>0){
    //             current1=floor(nums[i]/((double)k));
    //         }
    //         else{
    //             current1=ceil(nums[i]/((double)k));
    //         }
    //         long long maxi=max(reccall1,reccall2);
    //         if(maxi>0)
    //         current1+=maxi;
    //         long long current=nums[i];
    //         if(reccall>0)
    //         current+=reccall;
    //         ans=max(ans,max(current,current1));
    //         return dp[i][started]=max(current,current1);
    //     }
    //     else{
    //         if(started==1){
    //             long long current;
    //             if(nums[i]>0){
    //                 current=floor(nums[i]/((double)k));
    //             }
    //             else{
    //                 current=ceil(nums[i]/((double)k));
    //             }
    //             long long reccall=solve(i+1,1,nums,n,k,dp,ans);
    //             long long reccall1=solve(i+1,2,nums,n,k,dp,ans);
    //             long long maxi=max(reccall,reccall1);
    //             if(maxi>0)
    //             current+=maxi;
    //             ans=max(ans,current);
    //             return dp[i][started]=current;
    //         }
    //         if(started==2){
    //             long long reccall=solve(i+1,2,nums,n,k,dp,ans);
    //             long long current=nums[i];
    //             if(reccall>0)
    //             current+=reccall;
    //             ans=max(ans,current);
    //             return dp[i][started]=current;
    //         }
    //     }
    //     return LLONG_MIN;
    // }
    // long long maxSubarraySum(vector<int>& nums, int k) {
    //     // long long ans=LLONG_MIN;
    //     // int n=nums.size();
    //     // long long sum=0;
    //     // for(int i=0;i<n;i++){
    //     //     long long current=(1LL*nums[i]*k);
    //     //     sum+=current;
    //     //     ans=max(ans,sum);
    //     //     if(sum<0) sum=0;
    //     // }
    //     // sum=0;
    //     // int ansS,ansE;
    //     // int start=0;
    //     // long long ans1=LLONG_MAX;
    //     // for(int i=0;i<n;i++){
    //     //     sum+=nums[i];
    //     //     if(sum<=ans1){
    //     //         ans1=sum;
    //     //         ansS=start;
    //     //         ansE=i;
    //     //     }
    //     //     if(sum>0){
    //     //         start=i+1;
    //     //         sum=0;
    //     //     }
    //     // }
    //     // for(int i=ansS;i<=ansE;i++){
    //     //     if(nums[i]>0){
    //     //         nums[i]=floor(nums[i]/((double)k));
    //     //     }
    //     //     else{
    //     //         nums[i]=ceil(nums[i]/((double)k));
    //     //     }
    //     // }
    //     // sum=0;
    //     // for(int i=0;i<n;i++){
    //     //     long long current=nums[i];
    //     //     sum+=current;
    //     //     ans=max(ans,sum);
    //     //     if(sum<0) sum=0;
    //     // }
    //     // return ans;

    //     int n=nums.size();
    //     vector<vector<long long>>dp(n+1,vector<long long>(3,-1));
    //     long long ans=LLONG_MIN;
    //     solve(0,0,nums,n,k,dp,ans);
    //     long long sum=0;
    //     for(int i=0;i<n;i++){
    //         sum+=nums[i];
    //         ans=max(ans,sum*k);
    //         if(sum<0){
    //             sum=0;
    //         }
    //     }
    //     return ans;
    // }




    
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=LLONG_MIN;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans=max(ans,sum*k);
            if(sum<0){
                sum=0;
            }
        }
        vector<vector<long long>>dp(n+1,vector<long long>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int started=0;started<=2;started++){
                if(started==0){
                    long long reccall=dp[i+1][0];
                    long long reccall1=dp[i+1][1];
                    long long reccall2=dp[i+1][2];
                    long long current1;
                    if(nums[i]>0){
                        current1=floor(nums[i]/((double)k));
                    }
                    else{
                        current1=ceil(nums[i]/((double)k));
                    }
                    long long maxi=max(reccall1,reccall2);
                    if(maxi>0)
                    current1+=maxi;
                    long long current=nums[i];
                    if(reccall>0)
                    current+=reccall;
                    dp[i][started]=max(current,current1);
                }
                else if(started==1){
                    long long current;
                    if(nums[i]>0){
                        current=floor(nums[i]/((double)k));
                    }
                    else{
                        current=ceil(nums[i]/((double)k));
                    }
                    long long reccall=dp[i+1][1];
                    long long reccall1=dp[i+1][2];
                    long long maxi=max(reccall,reccall1);
                    if(maxi>0)
                    current+=maxi;
                    dp[i][started]=current;
                }
                else if(started==2){
                    long long reccall=dp[i+1][2];
                    long long current=nums[i];
                    if(reccall>0)
                    current+=reccall;
                    dp[i][started]=current;
                }
                ans=max(ans,dp[i][started]);
            }
        }
        return ans;
    }
};