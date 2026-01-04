class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        unordered_map<int,int>mpp;
        for(auto &each:restrictions){
            mpp[each[0]]=each[1];
        }
        vector<int>ans(n,0);
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]+diff[i-1];
            if(mpp.count(i))
            ans[i]=min(ans[i],mpp[i]);
        }
        int maxi=ans[n-1];
        for(int i=n-2;i>=1;i--){
            ans[i]=min(ans[i],ans[i+1]+diff[i]);
            maxi=max(maxi,ans[i]);
        }
        return maxi;
    }
};