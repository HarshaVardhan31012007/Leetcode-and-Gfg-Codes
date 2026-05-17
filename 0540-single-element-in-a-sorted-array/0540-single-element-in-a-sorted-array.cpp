class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int ans;
        while(s<=e){
            int mid=s+(e-s)/2;
            if((mid==0||nums[mid]!=nums[mid-1])&&(mid==(n-1)||nums[mid]!=nums[mid+1]))
            return nums[mid];
            if(mid+1<n&&nums[mid]==nums[mid+1]){
                if(!(mid&1)){
                    s=mid+2;
                }
                else{
                    ans=nums[mid];
                    e=mid-1;
                }
            }
            else{
                if(mid&1){
                    s=mid+1;
                }
                else{
                    ans=nums[mid];
                    e=mid-2;
                }
            }
        }
        return ans;
    }
};