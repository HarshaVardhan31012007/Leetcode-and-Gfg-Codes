class Solution {
public:
    int findMin(vector<int>& nums) {
        // int s=0;int e=(int)nums.size()-1;
        // while(s<=e){
        //     int mid=s+(e-s)/2;
        //     if(mid+1<nums.size()&&nums[mid]>nums[mid+1])
        //     return nums[mid+1];
        //     if(nums[s]<=nums[mid]){
        //         s=mid+1;
        //     }
        //     else{
        //        e=mid-1;
        //     }
        // }
        // return nums[0];



         int s=0;int e=(int)nums.size()-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(mid>0&&nums[mid]<nums[mid-1])
            return nums[mid];
            if(nums[s]<=nums[mid]&&nums[s]>nums[e]){
                s=mid+1;
            }
            else{
               e=mid-1;
            }
        }
        return nums[0];
    }
};