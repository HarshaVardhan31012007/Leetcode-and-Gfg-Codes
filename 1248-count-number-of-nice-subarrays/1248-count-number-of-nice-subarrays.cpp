class Solution {
public:
    // int solve(vector<int>&nums,int k){
    //     int n=nums.size();
    //     int i=0;
    //     int j=0;
    //     int c=0;
    //     int ans=0;
    //     while(j<n){
    //        if(nums[j]&1) c++;
    //        while(c>k){
    //           if(nums[i]&1) c--;
    //           i++;
    //        }
    //        ans+=(j-i+1);
    //        j++;
    //     }
    //     return ans;
    // }
    // int numberOfSubarrays(vector<int>& nums, int k) {
    //     return solve(nums,k)-solve(nums,k-1);
    // }



    int solve(vector<int>&nums,int k){
        int n=nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int ans=0;
        while(j<n){
           sum+=(nums[j]%2);
           while(sum>k){
              sum-=(nums[i]%2);
              i++;
           }
           ans+=(j-i+1);
           j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};