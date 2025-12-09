class Solution {
public:
    // typedef long long ll;
    // const int mod=1e9+7;
    // ll solve(vector<int>&nums,ll k,ll i,vector<ll>&dp){
    //     if(i>=nums.size()) return 1;
    //     if(dp[i]!=-1) return dp[i];
    //     ll s=i;ll maxi=LLONG_MIN;
    //     ll e=i;ll mini=LLONG_MAX;
    //     while(e<nums.size()){
    //         maxi=max(maxi,(long long)nums[e]);
    //         mini=min(mini,(long long)nums[e]);
    //         if(maxi-mini<=k){
    //             e++;
    //         }
    //         else
    //         break;
    //     }
    //     ll count=e-s;
    //     ll ans=0;
    //     for(int j=1;j<=count;j++){
    //         ans=(ans+solve(nums,k,i+j,dp))%mod;
    //     }
    //     return dp[i]=ans;
    // }
    // int countPartitions(vector<int>& nums, int k) {
    //     vector<ll>dp(nums.size()+1,-1);
    //     ll i=0;
    //     return (int)solve(nums,(long long)k,i,dp);
    // }




    // typedef long long ll;
    // const int mod=1e9+7;
    // ll solve(vector<int>&nums,ll k,ll i,vector<ll>&dp,vector<ll>&count){
    //     if(i>=nums.size()) return 1;
    //     if(dp[i]!=-1) return dp[i];
    //     ll c=count[i];
    //     ll ans=0;
    //     for(int j=1;j<=c;j++){
    //         ans=(ans+solve(nums,k,i+j,dp,count))%mod;
    //     }
    //     return dp[i]=ans;
    // }
    // int countPartitions(vector<int>& nums, int k) {
    //     vector<ll>count(nums.size());
    //     for(int i=0;i<nums.size();i++){
    //             ll s=i;ll maxi=LLONG_MIN;
    //             ll e=i;ll mini=LLONG_MAX;
    //             while(e<nums.size()){
    //                 maxi=max(maxi,(long long)nums[e]);
    //                 mini=min(mini,(long long)nums[e]);
    //                 if(maxi-mini<=k){
    //                     e++;
    //                 }
    //                 else
    //                 break;
    //             }
    //             ll c=e-s;
    //             count[i]=c;
    //     }
    //     vector<ll>dp(nums.size()+1,-1);
    //     ll i=0;
    //     return (int)solve(nums,(long long)k,i,dp,count);
    // }





    // typedef long long ll;
    // const int mod=1e9+7;
    // ll solve(vector<int>&nums,ll k,ll i,vector<ll>&dp){
    //     if(i>=nums.size()) return 1;
    //     if(dp[i]!=-1) return dp[i];
    //     ll maxi=LLONG_MIN;
    //     ll mini=LLONG_MAX;
    //     ll ans=0;
    //     for(int j=i;j<nums.size();j++){
    //         maxi=max(maxi,(ll)nums[j]);
    //         mini=min(mini,(ll)nums[j]);
    //         if(maxi-mini>k) break;
    //         ans=(ans+solve(nums,k,j+1,dp))%mod;
    //     }
    //     return dp[i]=ans;
    // }
    // int countPartitions(vector<int>& nums, int k) {
    //     vector<ll>dp(nums.size()+1,-1);
    //     ll i=0;
    //     return (int)solve(nums,(long long)k,i,dp);
    // }



    const int mod=1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        vector<int>dp(nums.size()+1,0);
        vector<int>prefix(nums.size()+1,0);
        int i=0;
        int j=0;
        deque<int>maxi;
        deque<int>mini;
        prefix[0]=1;
        dp[0]=1;
        while(j<nums.size()){
            while(!maxi.empty()&&nums[j]>nums[maxi.back()]){
                maxi.pop_back();
            }
            maxi.push_back(j);
            while(!mini.empty()&&nums[j]<nums[mini.back()]){
                mini.pop_back();
            }
            mini.push_back(j);
            while(i<=j&&nums[maxi.front()]-nums[mini.front()]>k){
                i++;
                if(maxi.front()<i) maxi.pop_front();
                if(!mini.empty()&&mini.front()<i) mini.pop_front();
            }
            dp[j+1]=(prefix[j]-(i>0?prefix[i-1]:0)+mod)%mod;//treat like 1-indexed 
            prefix[j+1]=(prefix[j]+dp[j+1])%mod;
            j++;
        }
        return dp[nums.size()];
    }
};