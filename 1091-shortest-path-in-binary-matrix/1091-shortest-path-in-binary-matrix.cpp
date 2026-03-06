class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>visited(m,vector<int>(n,0));
        if(!grid[0][0]){
           q.push({0,0});
           visited[0][0]=1;
        }
        int dist=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto top=q.front();
                int r=top.first;int c=top.second;
                q.pop();
                if(r==m-1&&c==n-1) return dist;
                int dx[]={-1,-1,-1,0,0,0,1,1,1};
                int dy[]={-1,0,1,-1,0,1,-1,0,1};
                for(int i=0;i<9;i++){
                    int x=r+dx[i];
                    int y=c+dy[i];
                    if(x<0||y<0||x>=m||y>=n) continue;
                    if(grid[x][y]==0&&!visited[x][y]){
                       q.push({x,y});
                       visited[x][y]=1;
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};