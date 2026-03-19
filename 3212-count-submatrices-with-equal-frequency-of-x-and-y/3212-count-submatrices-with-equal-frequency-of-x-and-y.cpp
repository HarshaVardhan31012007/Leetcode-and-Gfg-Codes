class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>v(m+1,vector<int>(n+1,0));
        vector<vector<int>>v1(m+1,vector<int>(n+1,0));
        int ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int curr=((grid[i-1][j-1]=='.')?0:(grid[i-1][j-1]=='X'?1:-1));
                v[i][j]=curr+v[i-1][j]+v[i][j-1]-v[i-1][j-1];
                int curr1=((grid[i-1][j-1]=='.')?1:0);
                v1[i][j]=curr1+v1[i-1][j]+v1[i][j-1]-v1[i-1][j-1];
                if(v1[i][j]!=(i*j)&&v[i][j]==0){
                   ans++;
                }
            }
        }
        return ans;
    }
};