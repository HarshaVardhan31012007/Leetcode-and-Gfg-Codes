class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(mid+1<n&&nums[mid+1]<nums[mid]) return nums[mid+1];
            if(nums[s]<=nums[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return nums[0];
    }
};