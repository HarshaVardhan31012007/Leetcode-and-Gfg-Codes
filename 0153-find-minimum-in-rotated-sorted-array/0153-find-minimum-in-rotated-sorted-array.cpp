class Solution {
public:
    int findMin(vector<int>& nums) {
        // int n=nums.size();
        // int s=0;
        // int e=n-1;
        // while(s<=e){
        //     int mid=s+(e-s)/2;
        //     if(mid+1<n&&nums[mid+1]<nums[mid]) return nums[mid+1];
        //     if(nums[s]<=nums[mid]){
        //         s=mid+1;
        //     }
        //     else{
        //         e=mid-1;
        //     }
        // }
        // return nums[0];


        // int n=nums.size();
        // int s=0;
        // int e=n-1;
        // while(s<e){
        //     int mid=s+(e-s)/2;
        //     if(nums[mid]>nums[e]){
        //         s=mid+1;
        //     }
        //     else{
        //         e=mid;
        //     }
        // }
        // return nums[e];



        int n=nums.size();
        int s=0;
        int e=n-1;
        int ans=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[s]<=nums[mid]){
               ans=min(ans,nums[s]);
               s=mid+1;
            }
            else{
               ans=min(ans,nums[mid]);
               e=mid-1;
            }
        }
        return ans;
    }
};