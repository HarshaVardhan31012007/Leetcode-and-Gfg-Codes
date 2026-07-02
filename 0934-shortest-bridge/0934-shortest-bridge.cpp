class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int r,c;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    r=i;
                    c=j;
                    break;
                }
            }
        }
        queue<pair<int,int>>q1;
        queue<vector<int>>q2;
        q1.push({r,c});
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        vector<vector<int>>visited(m,vector<int>(n,0));
        visited[r][c]=1;
        while(!q1.empty()){
            int i=q1.front().first;
            int j=q1.front().second;
            q1.pop();
            for(int k=0;k<4;k++){
                int newi=i+dx[k];
                int newj=j+dy[k];
                if(newi<0||newj<0||newi>=m||newj>=n||visited[newi][newj]){
                    continue;
                }
                if(grid[newi][newj]==0){
                    q2.push({1,newi,newj});
                    visited[newi][newj]=1;
                    continue;
                }
                visited[newi][newj]=1;
                q1.push({newi,newj});
            }
        }
        while(!q2.empty()){
            int d=q2.front()[0];
            int i=q2.front()[1];
            int j=q2.front()[2];
            q2.pop();
            for(int k=0;k<4;k++){
                int newi=i+dx[k];
                int newj=j+dy[k];
                if(newi<0||newj<0||newi>=m||newj>=n||visited[newi][newj]==1) continue;
                visited[newi][newj]=1;
                if(grid[newi][newj]==1) return d;
                q2.push({d+1,newi,newj});
            }
        }
        return -1;
    }
};