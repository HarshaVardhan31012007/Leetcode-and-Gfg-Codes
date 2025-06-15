class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int s=0;
        // int e=nums.size()-1;
        // int ans=nums.size();
        // while(s<=e){
        //     int mid=s+(e-s)/2;
        //     if(nums[mid]==mid)
        //     s=mid+1;
        //     else{
        //         ans=mid;
        //         e=mid-1;
        //     }
        // }
        // return ans;

        
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=nums.size()&&nums[i]!=i)
            swap(nums[i],nums[nums[i]]);
            else
            i++;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i)
            return i;
        }
        return nums.size();
    }
};