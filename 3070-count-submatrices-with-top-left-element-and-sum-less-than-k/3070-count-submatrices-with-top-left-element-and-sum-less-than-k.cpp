class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m=grid.size();int n=grid[0].size();
        vector<vector<int>>prefix(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 prefix[i][j]=grid[i][j]+((i>0?prefix[i-1][j]:0)+(j>0?prefix[i][j-1]:0)-(i>0&&j>0?prefix[i-1][j-1]:0));
                 if(prefix[i][j]<=k) ans++;
            }
        }
        return ans;
    }
};