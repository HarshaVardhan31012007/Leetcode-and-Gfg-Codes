class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       unordered_map<int,int>mpp;
       vector<int>ans(2);
       int n=grid.size();
       for(int i=0;i<n*n;i++)
       mpp[i+1]=1;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mpp[grid[i][j]]==0)
             ans[0]=grid[i][j];
             mpp[grid[i][j]]=0;
        }
       }
       for(auto &each:mpp){
        if(each.second==1)
        ans[1]=each.first;
       }
       return ans;
    }
};