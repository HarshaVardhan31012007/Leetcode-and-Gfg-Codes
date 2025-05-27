class Solution {
public:
    bool possible(vector<int>&nums,int mid,int k){
        int c=1;int sum=0;
        for(int i=0;i<nums.size();i++){
           if(sum+nums[i]<=mid)
           sum+=nums[i];
           else{
            c++;
            if(c>k) return false;
            sum=nums[i];
           }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
        int s=*max_element(nums.begin(),nums.end());
        int e=accumulate(nums.begin(),nums.end(),0);
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(nums,mid,k)){
               ans=mid;
               e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
};