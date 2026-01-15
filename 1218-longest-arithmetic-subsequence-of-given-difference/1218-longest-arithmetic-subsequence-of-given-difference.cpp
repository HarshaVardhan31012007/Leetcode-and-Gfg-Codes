class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int>dp;
        int ans=0;
        for(int i=0;i<arr.size();i++){
            int before=0;
            if(dp.count(arr[i]-difference)){
                before=dp[arr[i]-difference];
            }
            dp[arr[i]]=1+before;
            ans=max(ans,dp[arr[i]]);
        }   
        return ans;
    }
};