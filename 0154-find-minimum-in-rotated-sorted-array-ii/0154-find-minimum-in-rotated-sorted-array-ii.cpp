class Solution {
public:
    int findMin(vector<int>& nums) {
        // int n = nums.size();
        // int s=0;
        // int e=n-1;
        // while(s<e){
        //     int mid=s+(e-s)/2;
        //     if(nums[mid]>nums[e]){
        //         s=mid+1;
        //     }
        //     else if(nums[mid]<nums[e]){
        //         e=mid;
        //     }
        //     else{
        //         e--;
        //     }
        // }
        // return nums[e];



        int n = nums.size();
        int s=0;
        int e=n-1;
        int ans=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(s==e) ans=min(ans,nums[s]);
            if(nums[mid]>nums[e]){
                ans=min(ans,nums[s]);
                s=mid+1;
            }
            else if(nums[mid]<nums[e]){
                ans=min(ans,nums[mid]);
                e=mid-1;
            }
            else{
                e--;
            }
        }
        return ans;
    }
};