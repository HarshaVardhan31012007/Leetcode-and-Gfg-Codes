class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        deque<vector<int>>q;
        q.push_back({grid[0][0],0,0});
        vector<vector<int>>minHealth(m,vector<int>(n,INT_MAX));
        minHealth[0][0]=grid[0][0];
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        int minH=INT_MAX;
        while(!q.empty()){
            int r=q.front()[1];
            int c=q.front()[2];
            int h=q.front()[0];
            q.pop_front();
            if(h!=minHealth[r][c]) continue;
            if(r==(m-1)&&c==(n-1)){
                minH=h;
                break;
            }
            for(int k=0;k<4;k++){
                int newr=r+dx[k];
                int newc=c+dy[k];
                if(newr<0||newc<0||newr>=m||newc>=n) continue;
                if(minHealth[newr][newc]==INT_MAX){
                    minHealth[newr][newc]=h+grid[newr][newc];
                    if(grid[newr][newc]==0)
                    q.push_front({minHealth[newr][newc],newr,newc});
                    else
                    q.push_back({minHealth[newr][newc],newr,newc});
                }
            }
        }
        return minH;
    }
};