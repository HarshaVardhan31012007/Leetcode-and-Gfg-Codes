class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // int n=nums.size();
        // int s=0;
        // int e=n-1;
        // int ans=-1;
        // while(s<=e){
        //     while(s<e&&nums[e]==nums[e-1]) e--;
        //     int mid=s+(e-s)/2;
        //     if(ans==-1||nums[mid]<=nums[ans])
        //     ans=mid;
        //     if(nums[mid]>=nums[e]){
        //        s=mid+1;
        //     }
        //     else{
        //        e=mid-1;
        //     }
        // }
        // if(ans>0){
        //     if(binary_search(nums.begin(),nums.begin()+ans,target))
        //     return true;
        // }
        // if(binary_search(nums.begin()+ans,nums.end(),target))
        // return true;
        // return false;



        int n=nums.size();
        int s=0;
        int e=n-1;
        int ans=-1;
        while(s<e){
            while(s<e&&nums[e]==nums[e-1]) e--;
            int mid=s+(e-s)/2;
            if(nums[mid]>=nums[e]){
               s=mid+1;
            }
            else{
               e=mid;
            }
        }
        if(binary_search(nums.begin(),nums.begin()+e,target))
        return true;
        if(binary_search(nums.begin()+e,nums.end(),target))
        return true;
        return false;
    }
};