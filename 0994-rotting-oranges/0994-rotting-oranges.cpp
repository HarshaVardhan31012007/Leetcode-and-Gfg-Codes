class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshc=0;
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(grid[i][j]==1)
               freshc++;
               if(grid[i][j]==2)
               q.push({i,j});  
            }
        }
        if(freshc==0) return 0;
        int nlevels=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto r=q.front().first;
                auto c=q.front().second;
                q.pop();
                int dx[]={-1,1,0,0};
                int dy[]={0,0,-1,1};
                for(int i=0;i<4;i++){
                    int newr=r+dx[i];
                    int newc=c+dy[i];
                    if(newr<0||newc<0||newr>=m||newc>=n) continue;
                    if(grid[newr][newc]==1){
                        grid[newr][newc]=2;
                        freshc--;
                        q.push({newr,newc});
                    }
                }
            }
            nlevels++;
        }
        return (freshc==0)?(nlevels-1):-1;
    }
};