class Solution {
public:
    typedef long long ll;
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        ll operations=0;
        ll ans=LLONG_MIN;
        ll j=0;ll i=0;ll sum=nums[0];
        while(j<nums.size()){
            while(j<nums.size()&&((nums[j]*(j-i+1)-sum)<=k)){
                ans=max(ans,j-i+1);
                j++;
                if(j<nums.size())  sum+=nums[j];
            }
            if(j<nums.size()){
                sum-=nums[i];
                i++;
            }
        }
        return ans;
    }
};