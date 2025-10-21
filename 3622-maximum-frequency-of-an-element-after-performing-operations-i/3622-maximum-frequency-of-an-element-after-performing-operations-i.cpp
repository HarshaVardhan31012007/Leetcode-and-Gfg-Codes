class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxi=-1e5;
        int mini=1e5;
        for(auto &each:nums){
            maxi=max(maxi,each);
            mini=min(mini,each);
        }
        vector<int>v(maxi+1,0);
        for(auto &each:nums){
            v[each]++;
        }
        for(int i=1;i<=maxi;i++)
        v[i]+=v[i-1];
        int ans=1;
        for(int curr=mini;curr<=maxi;curr++){
            int l=max(mini,curr-k);
            int r=min(maxi,curr+k);
            int f=v[curr]-v[curr-1];
            int extra=min(numOperations,v[r]-v[l-1]-f);
            ans=max(ans,f+extra);
        }
        return ans;
    }
};