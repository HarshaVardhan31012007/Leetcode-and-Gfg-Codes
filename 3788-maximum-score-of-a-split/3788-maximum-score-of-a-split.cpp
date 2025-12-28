class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        vector<long long>suffix(nums.size(),0);
        suffix[nums.size()-1]=nums[nums.size()-1];
        for(long long i=nums.size()-2;i>=0;i--){
            suffix[i]=min(suffix[i+1],1LL*nums[i]);
        }
        long long p=0;
        long long ans=LLONG_MIN;
        for(int i=0;i<(int)nums.size()-1;i++){
            p+=nums[i];
            ans=max(ans,p-suffix[i+1]);
        }
        return ans;
    }
};