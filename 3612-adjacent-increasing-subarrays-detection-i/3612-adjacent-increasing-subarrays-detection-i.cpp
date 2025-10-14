class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if(nums.size()<2*k) return false;
        // for(int i=0;i<=nums.size()-2*k;i++){
        //     int j=0;
        //     int prev=nums[i+j];
        //     j++;
        //     bool flag=1;
        //     for(;j<k&&flag;j++){
        //          if(nums[i+j]<=prev){
        //             flag=0;
        //          }
        //          prev=nums[i+j];
        //     }
        //     prev=nums[i+j];
        //     j++;
        //     for(;j<2*k&&flag;j++){
        //         if(nums[i+j]<=prev){
        //             flag=0;
        //         }
        //         prev=nums[i+j];
        //     }
        //     if(flag)
        //     return true;
        // }
        // return false;




        int prevCount=0;
        int currCount=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                currCount++;
            }
            else{
                prevCount=currCount;
                currCount=1;
            }
            if(currCount>=2*k)// 2*k in same subarray
            return true;
            if(min(prevCount,currCount)>=k)//k in previous array kin current array
            return true;
        }
        return false;
    }
};