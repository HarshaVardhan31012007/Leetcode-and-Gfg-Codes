class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        // if(n==1)
        // return 0;
        // if(nums[0]>nums[1])
        // return 0;
        // if(nums[n-1]>nums[n-2])
        // return n-1;
        // int start=1;
        // int ans=0;
        // int end=n-2;
        // while(start<=end){
        //     int mid=start+(end-start)/2;
        //     if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])
        //     return mid;
        //     else if(nums[mid]>nums[mid-1]){
        //         start=mid+1;
        //     }
        //     else{
        //     ans=mid;
        //     end=mid-1;
        // }
        // }
        // return ans;
        
        int start=0;
        int ans=0;
        int end=n-1;
        if(start==end)
        return start;
        while(start<=end){
            
            int mid=start+(end-start)/2;
            if(mid+1<n&&nums[mid]<nums[mid+1]){
                start=mid+1;
            }
            else{
            ans=mid;
            end=mid-1;
               }
        }
        return ans;
    }
};