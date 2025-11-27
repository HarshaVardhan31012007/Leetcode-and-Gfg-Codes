class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,pair<int,long long>>mpp;
        int rem=0;
        long long sum=0;
        long long ans=LLONG_MIN;
        for(int i=0;i<nums.size();i++){
           rem=(rem+1)%k;
           sum=sum+nums[i];
           if(rem==0){
            ans=max(ans,sum);
           }
           if(mpp.count(rem)){
                 ans=max(ans,sum-mpp[rem].second);
                 if(sum<mpp[rem].second)
                 mpp[rem]={i,sum};
           }
           else
           mpp[rem]={i,sum};
        }
        return ans;
    }
};