class Solution {
public:
    int solve(vector<int>&a,vector<int>&b,int i,int j,vector<vector<int>>&dp){
        if(i>=a.size()){
            if(j==0) return -1e9;
            else return 0;
        }
        if(j>=b.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int k=j;k<b.size();k++){
           maxi=max(1LL*maxi,1LL*a[i]*b[k]+solve(a,b,i+1,k+1,dp));
        }
        maxi=max(maxi,solve(a,b,i+1,j,dp));
        return dp[i][j]=maxi;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        return solve(nums1,nums2,0,0,dp);
    }
};