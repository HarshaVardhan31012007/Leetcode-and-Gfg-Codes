class Solution {
public:
    void dfs(vector<vector<char>>& grid,int i,int j,int m,int n){
        grid[i][j]='0';
        vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
        for(auto &each:dir){
            int newX=i+each.first;
            int newY=j+each.second;
            if(newX>=0 && newX<m &&newY>=0 && newY<n && grid[newX][newY]=='1'){
                dfs(grid,newX,newY,m,n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int islands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                  dfs(grid,i,j,m,n);
                  islands++;
                }
            }
        }
        return islands;
    }
};