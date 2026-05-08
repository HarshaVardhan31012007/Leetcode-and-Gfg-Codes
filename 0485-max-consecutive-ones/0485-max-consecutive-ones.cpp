class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int c=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]&&nums[i]==1){
                c++;
            }
            else{
                ans=max(ans,c);
                c=nums[i];
            }
        }
        ans=max(ans,c);
        return ans;
    }
};