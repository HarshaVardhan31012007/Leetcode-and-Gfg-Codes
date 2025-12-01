class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        // int ans=0;
        // for(int i=0;i<nums.size();i++){
        //     int j=i;
        //     while(j<nums.size()&&nums[j]==nums[i]){
        //         j++;
        //     }
        //     if(nums.size()-j>=k)
        //     ans+=j-i;
        //     i=j-1;
        // }
        // return ans;


        sort(nums.begin(),nums.end());
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int idx=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
            if(nums.size()-idx>=k){
                ans++;
            }
        }
        return ans;
    }
};