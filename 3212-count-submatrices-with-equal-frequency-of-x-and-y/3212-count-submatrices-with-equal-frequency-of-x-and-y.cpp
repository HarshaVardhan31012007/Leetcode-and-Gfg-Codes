class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<pair<int,int>>>v(m+1,vector<pair<int,int>>(n+1,{0,0}));
        int ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int curr=((grid[i-1][j-1]=='.')?0:(grid[i-1][j-1]=='X'?1:-1));
                v[i][j].first=curr+v[i-1][j].first+v[i][j-1].first-v[i-1][j-1].first;
                int curr1=((grid[i-1][j-1]=='.')?1:0);
                v[i][j].second=curr1+v[i-1][j].second+v[i][j-1].second-v[i-1][j-1].second;
                if(v[i][j].second!=(i*j)&&v[i][j].first==0){
                   ans++;
                }
            }
        }
        return ans;
    }
};