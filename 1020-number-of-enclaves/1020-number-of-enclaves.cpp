class Solution {
public:
    // int dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&visited,bool &flag){
    //     visited[r][c]=1;
    //     if(r==0||c==0||r==grid.size()-1||c==grid[0].size()-1) flag=true;
    //     int dx[]={-1,1,0,0};
    //     int dy[]={0,0,-1,1};
    //     int ans=1;
    //     for(int i=0;i<4;i++){
    //         int x=r+dx[i];
    //         int y=c+dy[i];
    //         if(x<0||y<0||x>=grid.size()||y>=grid[0].size()) continue;
    //         if(!visited[x][y]&&grid[x][y]==1){
    //             ans+=dfs(x,y,grid,visited,flag);
    //         }
    //     }
    //     return ans;
    // }
    // int numEnclaves(vector<vector<int>>& grid) {
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     vector<vector<int>>visited(m,vector<int>(n,0));
    //     int ans=0;
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(!visited[i][j]&&grid[i][j]==1){
    //                 bool flag=false;
    //                 int curr=dfs(i,j,grid,visited,flag);
    //                 if(!flag) ans+=curr;
    //             }
    //         }
    //     }
    //     return ans;
    // }



    void dfs(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&visited){
        visited[r][c]=1;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int x=r+dx[i];
            int y=c+dy[i];
            if(x<0||y<0||x>=grid.size()||y>=grid[0].size()) continue;
            if(!visited[x][y]&&grid[x][y]==1){
                dfs(x,y,grid,visited);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            if(!visited[i][0]&&grid[i][0]==1){
                dfs(i,0,grid,visited);
            }
             if(!visited[i][n-1]&&grid[i][n-1]==1){
                dfs(i,n-1,grid,visited);
            }
        }
        for(int i=0;i<n;i++){
            if(!visited[0][i]&&grid[0][i]==1){
                dfs(0,i,grid,visited);
            }
             if(!visited[m-1][i]&&grid[m-1][i]==1){
                dfs(m-1,i,grid,visited);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};