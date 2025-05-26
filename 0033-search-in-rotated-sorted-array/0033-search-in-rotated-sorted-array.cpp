class Solution {
public:
    // int getpivotIndex(vector<int>&nums){
    //     int s=0;
    //     int n=nums.size();
    //     int e=n-1;
    //     int mid=s+(e-s)/2;
    //     while(s<=e){
            
    //         if(s==e)
    //         return s;
    //         if(nums[mid]>nums[mid+1])
    //         return mid;
    //         else if(nums[s]>nums[mid])
    //         e=mid-1;
    //         else
    //         s=mid+1;
    //         mid=s+(e-s)/2;

    //     }
    //     return -1;
    // }

    int getpivotIndex(vector<int>&nums){
        int s=0;
        int n=nums.size();
        int e=n-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            
            if(s==e)
            return s;
            if(nums[mid]>nums[mid+1])
            return mid;
            else if(nums[mid]>nums[e]||nums[s]<nums[e])
            s=mid+1;
            else
            e=mid-1;
            mid=s+(e-s)/2;

        }
        return -1;
    }
    int binarysearch(int s,int e,int target,vector<int>&nums){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target)
            return mid;
            if(nums[mid]>target)
            e=mid-1;
            if(nums[mid]<target)
            s=mid+1;
            mid=s+(e-s)/2;

        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        //optimization
        // if(n==1){
        //     if(target==nums[0]) return 0;
        //     return -1;
        // }
        // int pivotIndex=0;int s=0;int e=nums.size()-1;
        // ///no pivotIndex
        // if(nums[s]<nums[e]) pivotIndex=e;
        // else pivotIndex=getpivotIndex(nums);
        int pivotIndex=getpivotIndex(nums);
        if(target>=nums[0]&&target<=nums[pivotIndex]){
            int ans=binarysearch(0,pivotIndex,target,nums);
            return ans;
        }
        // else if(pivotIndex+1<n&&target>=nums[pivotIndex+1]&&target<=nums[n-1])
        else{
            int ans=binarysearch(pivotIndex+1,n-1,target,nums);
            return ans;
        }
        // else{
        //     int ans=binarysearch(pivotIndex+1,n-1,target,nums);
        //     return ans;
        // }
        return -1;
    }
};