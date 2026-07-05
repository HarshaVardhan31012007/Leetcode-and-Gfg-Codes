class Solution {
public:
    vector<vector<int>>fireTime;
    const int INF=1e9;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    void completeFireTime(vector<vector<int>>&grid){
        int m=grid.size();
        int n=grid[0].size();
        fireTime.assign(m,vector<int>(n,INF));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    fireTime[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=r+dx[i];
                int newc=c+dy[i];
                if(newr<0||newc<0||newr>=m||newc>=n||fireTime[newr][newc]!=INF||grid[newr][newc]==2) continue;
                fireTime[newr][newc]=fireTime[r][c]+1;
                q.push({newr,newc});
            }
        }
    }
    bool canReach(vector<vector<int>>&grid,int wait){
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>dist(m,vector<int>(n,-1));
        dist[0][0]=wait;
        q.push({0,0});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=r+dx[i];
                int newc=c+dy[i];
                if(newr<0||newc<0||newr>=m||newc>=n||dist[newr][newc]!=-1||grid[newr][newc]==2) continue;
                if(newr==m-1&&newc==n-1){
                    if(dist[r][c]+1<=fireTime[newr][newc]){
                        dist[newr][newc]=dist[r][c]+1;
                        return true;
                    }
                }
                else{
                    if(dist[r][c]+1<fireTime[newr][newc]){
                        dist[newr][newc]=dist[r][c]+1;
                        q.push({newr,newc});
                    }
                }
            }
        }
        return false;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        completeFireTime(grid);
        int m=grid.size();
        int n=grid[0].size();
        int s=0;int e=m*n;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(canReach(grid,mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        if(ans==m*n) ans=INF;
        return ans;
    }
};