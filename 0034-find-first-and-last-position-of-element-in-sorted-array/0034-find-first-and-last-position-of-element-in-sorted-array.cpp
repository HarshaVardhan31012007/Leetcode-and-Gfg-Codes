class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int ans1=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]>=target){
                if(nums[mid]==target)
                ans1=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        int ans2=-1;s=0;e=n-1;
         while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]<=target){
                if(nums[mid]==target)
                ans2=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return {ans1,ans2};
    }
};