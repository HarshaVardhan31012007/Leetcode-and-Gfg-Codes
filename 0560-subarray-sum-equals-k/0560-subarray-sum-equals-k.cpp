class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int sum=0;
        int ans=0;
        for(int i=0;i<(int)nums.size();i++){
            sum+=nums[i];
            if(sum==k)
            ans++;
            if(mpp.count(sum-k)){
                ans+=mpp[sum-k];
            }
            mpp[sum]++;
        }
        return ans;
    }
};