class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        int i=0;
        while(i<n){
            if((i+1<n)&&nums[i]==nums[i+1])
            i+=2;
            else{
                ans=nums[i];
                break;
            }
        }
        return ans;
    }
};