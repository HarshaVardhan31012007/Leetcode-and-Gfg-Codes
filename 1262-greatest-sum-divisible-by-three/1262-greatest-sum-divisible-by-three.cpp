class Solution {
public:
    // bool check(vector<int>&nums,int i,int t){
    //     if(i>=nums.size()){
    //         if(t==0)
    //         return true;
    //         return false;
    //     }
    //     bool l=false;
    //     if(t>=nums[i])
    //     l=check(nums,i+1,t-nums[i]);
    //     bool e=check(nums,i+1,t);
    //     return l||e;
    // }
    // int maxSumDivThree(vector<int>& nums) {
    //     int sum=accumulate(nums.begin(),nums.end(),0);
    //     int rem=sum%3;
    //     if(rem==0) return sum;
    //     while(rem<=sum){
    //         if(check(nums,0,rem))
    //           return sum-rem;
    //         rem+=3;
    //     }
    //     return 0;
    // }


    //  bool check(vector<int>&nums,vector<vector<int>>&dp,int t){
    //     for(int i=nums.size()-1;i>=0;i--){
    //         for(int j=0;j<=t;j++){
    //             bool l=false;
    //             if(j>=nums[i])
    //             l=dp[i+1][j-nums[i]];
    //             bool e=dp[i+1][j];
    //             dp[i][j]=l||e;
    //         }
    //     }
    //     return dp[0][t];
    // }
    // int maxSumDivThree(vector<int>& nums) {
    //     int sum=accumulate(nums.begin(),nums.end(),0);
    //     int rem=sum%3;
    //     if(rem==0) return sum;
    //     while(rem<=sum){
    //         vector<vector<int>>dp(nums.size()+1,vector<int>(rem+1,0));
    //         dp[nums.size()][0]=1;
    //         if(check(nums,dp,rem))
    //           return sum-rem;
    //         rem+=3;
    //     }
    //     return 0;
    // }



    bool check(vector<int>&nums,vector<int>&curr,int &t){
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=t;j>=0;j--){
                bool l=false;
                if(j>=nums[i])
                l=curr[j-nums[i]];
                bool e=curr[j];
                curr[j]=l||e;
            }
        }
        return curr[t];
    }
    int maxSumDivThree(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int rem=sum%3;
        if(rem==0) return sum;
        while(rem<=sum){
            vector<int>curr(rem+1,0);
            curr[0]=1;
            if(check(nums,curr,rem))
              return sum-rem;
            rem+=3;
        }
        return 0;
    }
};