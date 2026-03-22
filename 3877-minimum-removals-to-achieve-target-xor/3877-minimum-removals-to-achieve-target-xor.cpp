class Solution {
public:
    int solve(vector<int>&nums,int i,int xo,vector<vector<int>>&dp,int target){
        if(i>=nums.size()){
            if(xo==target){
                return 0;
            }
            else return INT_MIN;
        }
        if(dp[i][xo]!=-1) return dp[i][xo];
        int inc=1+solve(nums,i+1,xo^nums[i],dp,target);
        int exc=solve(nums,i+1,xo,dp,target);
        return dp[i][xo]=max(inc,exc);
    }
    int minRemovals(vector<int>& nums, int target) {
        // long long n=nums.size();
        // long long mid=n/2;
        // unordered_map<int,long long>mpp;
        // for(int i=0;i<(1LL<<mid);i++){
        //     long long temp=i;
        //     long long mask=0;
        //     long long count=0;
        //     for(int j=0;j<mid;j++){
        //         int bit=temp&1;
        //         if(bit){
        //             mask=mask^nums[j];
        //             count++;
        //         }
        //         temp=temp>>1;
        //     }
        //     if(!mpp.count(mask))
        //     mpp[mask]=count;
        //     else
        //     mpp[mask]=max(mpp[mask],count);
        // }
        // long long size=n-mid;
        // int ans=INT_MAX;
        // for(int i=0;i<(1LL<<size);i++){
        //     long long temp=i;
        //     long long mask=0;
        //     long long count=0;
        //     for(int j=0;j<size;j++){
        //         int bit=temp&1;
        //         if(bit){
        //             mask=mask^nums[mid+j];
        //             count++;
        //         }
        //         temp=temp>>1;
        //     }
        //     int required=target^mask;
        //     if(mpp.count(required)){
        //         ans=min(1LL*ans,n-mpp[required]-count);
        //     }
        // }
        // return (ans==INT_MAX)?-1:ans;



        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(16384,-1));
        int ans=solve(nums,0,0,dp,target);
        if(ans<0) return -1;
        return n-ans;
    }
};