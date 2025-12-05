class Solution {
public:
    typedef long long ll;
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        vector<ll>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        } 
        vector<ll>suffix(n,0);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            ll curr=suffix[i+1]-prefix[i];
            if(curr%2==0)
            ans++;
        }
        return ans;
    }
};