class Solution {
public:
    const int mod=1e9+7;
    long long solve(vector<int>&nums1,vector<int>&nums2,int i,int m,int n,int curr,vector<vector<long long>>&dp,unordered_map<int,int>&index1,unordered_map<int,int>&index2){
        if(curr==0&&i>=m) return 0;
        if(curr==1&&i>=n) return 0;
        if(dp[i][curr]!=-1) return dp[i][curr];
        int val=(curr==0?nums1[i]:nums2[i]);
        auto &mpp=(curr==0?index1:index2);
        long long ans=LLONG_MIN;
        if(mpp.count(val)){
            ans=max(ans,val+solve(nums1,nums2,mpp[val]+1,m,n,!curr,dp,index1,index2));
        }
        ans=max(ans,val+solve(nums1,nums2,i+1,m,n,curr,dp,index1,index2));
        return dp[i][curr]=ans;
    }
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        unordered_map<int,int>index;
        unordered_map<int,int>index1;
        unordered_map<int,int>index2;
        for(int i=0;i<nums1.size();i++) index[nums1[i]]=i;
        for(int i=0;i<nums2.size();i++){
            if(index.count(nums2[i])){
                index1[nums2[i]]=i;
                index2[nums2[i]]=index[nums2[i]];
            }
        }
        vector<vector<long long>>dp(max(m,n)+1,vector<long long>(2,-1));
        return max(solve(nums1,nums2,0,m,n,0,dp,index1,index2)%mod,solve(nums1,nums2,0,m,n,1,dp,index1,index2)%mod);
    }
};