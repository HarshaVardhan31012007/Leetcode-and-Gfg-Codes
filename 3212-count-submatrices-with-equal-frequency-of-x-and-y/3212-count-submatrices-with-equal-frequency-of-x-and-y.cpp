class Solution {
public:
    // int numberOfSubmatrices(vector<vector<char>>& grid) {
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     vector<vector<pair<int,int>>>v(m+1,vector<pair<int,int>>(n+1,{0,0}));
    //     int ans=0;
    //     for(int i=1;i<=m;i++){
    //         for(int j=1;j<=n;j++){
    //             int curr=((grid[i-1][j-1]=='.')?0:(grid[i-1][j-1]=='X'?1:-1));
    //             v[i][j].first=curr+v[i-1][j].first+v[i][j-1].first-v[i-1][j-1].first;
    //             int curr1=((grid[i-1][j-1]=='.')?1:0);
    //             v[i][j].second=curr1+v[i-1][j].second+v[i][j-1].second-v[i-1][j-1].second;
    //             if(v[i][j].second!=(i*j)&&v[i][j].first==0){
    //                ans++;
    //             }
    //         }
    //     }
    //     return ans;
    // }



     int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<pair<int,int>>v(n+1,{0,0});
        int ans=0;
        for(int i=1;i<=m;i++){
            int sum=0;int atleastX=0;
            for(int j=1;j<=n;j++){
                if(grid[i-1][j-1]=='X'){
                    sum++;
                    atleastX=1;
                }
                else if(grid[i-1][j-1]=='Y'){
                    sum--;
                }
                v[j].first+=sum;
                v[j].second|=atleastX;
                if(v[j].first==0&&v[j].second){
                    ans++;
                }
            }
        }
        return ans;
    }
};