class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>v(2*limit+2,0);
        for(int i=0;i<n/2;i++){
            int mini=min(nums[i],nums[n-i-1])+1;
            int maxi=max(nums[i],nums[n-i-1])+limit;
            int curr=nums[i]+nums[n-i-1];
            v[2]+=2;
            v[mini]+=-2;
            v[mini]+=1;
            v[curr]+=-1;
            v[curr+1]+=1;
            v[maxi+1]+=-1;
            v[maxi+1]+=2;
        }
        int mini=INT_MAX;
        for(int i=2;i<=2*limit;i++){
            v[i]+=v[i-1];
            mini=min(mini,v[i]);
        }
        return mini;
    }
};