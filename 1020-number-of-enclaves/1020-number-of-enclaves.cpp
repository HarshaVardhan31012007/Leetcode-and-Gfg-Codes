class Solution {
public:
    int dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&visited,bool &flag){
        visited[r][c]=1;
        if(r==0||c==0||r==grid.size()-1||c==grid[0].size()-1) flag=true;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        int ans=1;
        for(int i=0;i<4;i++){
            int x=r+dx[i];
            int y=c+dy[i];
            if(x<0||y<0||x>=grid.size()||y>=grid[0].size()) continue;
            if(!visited[x][y]&&grid[x][y]==1){
                ans+=dfs(x,y,grid,visited,flag);
            }
        }
        return ans;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&grid[i][j]==1){
                    bool flag=false;
                    int curr=dfs(i,j,grid,visited,flag);
                    if(!flag) ans+=curr;
                }
            }
        }
        return ans;
    }
};