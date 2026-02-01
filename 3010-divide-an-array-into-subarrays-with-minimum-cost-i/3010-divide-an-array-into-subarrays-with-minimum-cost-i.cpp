class Solution {
public:
    int minimumCost(vector<int>& nums) {
        // int ans=INT_MAX;
        // int mini=INT_MAX;
        // for(int i=1;i<nums.size();i++){
        //    if(mini!=INT_MAX)
        //    ans=min(ans,nums[0]+nums[i]+mini);
        //    mini=min(mini,nums[i]);
        // }
        // return ans;


        int m1=INT_MAX;int m2=INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(m1>nums[i]){
                m2=m1;
                m1=nums[i];
            }
            else if(m2>nums[i]){
                m2=nums[i];
            }
        }
        return nums[0]+m1+m2;
    }
};