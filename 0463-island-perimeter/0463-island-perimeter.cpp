class Solution {
public:
    int bfs(int &row,int &col,vector<vector<int>>&grid,vector<vector<int>>&visited){
        queue<pair<int,int>>q;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        int m=grid.size();
        int n=grid[0].size();
        q.push({row,col});
        visited[row][col]=1;
        int total=0;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=r+dx[i];
                int newc=c+dy[i];
                if(newr<0||newc<0||newr>=m||newc>=n){
                    total++;
                    continue;
                }
                if(grid[newr][newc]==0) total++;
                if(visited[newr][newc]||grid[newr][newc]==0) continue; 
                visited[newr][newc]=1;
                q.push({newr,newc});
            }
        }
        return total;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&grid[i][j]>0){
                    ans=bfs(i,j,grid,visited);
                }
            }
        }
        return ans;
    }
};