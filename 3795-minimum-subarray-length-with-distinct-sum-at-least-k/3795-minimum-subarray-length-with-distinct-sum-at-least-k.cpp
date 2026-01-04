class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int i=0;int j=0;
        int ans=INT_MAX;
        unordered_map<int,int>mpp;
        long long int sum=0;
        while(j<nums.size()){
            if(!mpp.count(nums[j])){
                sum+=nums[j];
                mpp[nums[j]]=j;
            }
            while(i<=j&&sum>=k){
                ans=min(ans,j-i+1);
                int idx=mpp[nums[i]];
                if(idx==i){
                    sum-=nums[i];
                    mpp.erase(nums[i]);
                }
                i++;
            }
            mpp[nums[j]]=j;
            j++;
        }
        return ans==INT_MAX?-1:ans;
    }
};