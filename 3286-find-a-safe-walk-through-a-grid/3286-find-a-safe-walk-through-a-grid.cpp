class Solution {
public:
    // bool solve(vector<vector<int>>&grid,int i,int j,int m,int n,int health){
    //     if(i<0||j<0||i>=m||j>=n||grid[i][j]==-1||health<=0) return false;
    //     if(i==m-1&&j==n-1) return (health-grid[i][j])>0;
    //     int val=grid[i][j];
    //     grid[i][j]=-1;
    //     bool ans=solve(grid,i,j-1,m,n,health-val)||solve(grid,i,j+1,m,n,health-val)||solve(grid,i-1,j,m,n,health-val)||solve(grid,i+1,j,m,n,health-val);
    //     grid[i][j]=val;
    //     return ans;
    // }
    // bool findSafeWalk(vector<vector<int>>& grid, int health) {
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     return solve(grid,0,0,m,n,health);
    // }



    
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        pq.push({grid[0][0],0,0});
        vector<vector<int>>minHealth(m,vector<int>(n,INT_MAX));
        minHealth[0][0]=grid[0][0];
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        int minH=INT_MAX;
        while(!pq.empty()){
            int r=pq.top()[1];
            int c=pq.top()[2];
            int h=pq.top()[0];
            pq.pop();
            if(h!=minHealth[r][c]) continue;
            if(r==(m-1)&&c==(n-1)){
                minH=h;
                break;
            }
            for(int k=0;k<4;k++){
                int newr=r+dx[k];
                int newc=c+dy[k];
                if(newr<0||newc<0||newr>=m||newc>=n) continue;
                if(h+grid[newr][newc]<minHealth[newr][newc]){
                    minHealth[newr][newc]=h+grid[newr][newc];
                    if(minHealth[newr][newc]>=health)  continue;
                    pq.push({minHealth[newr][newc],newr,newc});
                }
            }
        }
        return health>minH;



        // int m=grid.size();
        // int n=grid[0].size();
        // deque<vector<int>>q;
        // q.push_back({grid[0][0],0,0});
        // vector<vector<int>>minHealth(m,vector<int>(n,INT_MAX));
        // minHealth[0][0]=grid[0][0];
        // int dx[]={-1,1,0,0};
        // int dy[]={0,0,-1,1};
        // int minH=INT_MAX;
        // while(!q.empty()){
        //     int r=q.front()[1];
        //     int c=q.front()[2];
        //     int h=q.front()[0];
        //     q.pop_front();
        //     if(h!=minHealth[r][c]) continue;
        //     if(r==(m-1)&&c==(n-1)){
        //         return true;
        //     }
        //     for(int k=0;k<4;k++){
        //         int newr=r+dx[k];
        //         int newc=c+dy[k];
        //         if(newr<0||newc<0||newr>=m||newc>=n) continue;
        //         if(minHealth[newr][newc]==INT_MAX){
        //             minHealth[newr][newc]=h+grid[newr][newc];
        //             if(minHealth[newr][newc]>=health) continue;
        //             if(grid[newr][newc]==0)
        //             q.push_front({minHealth[newr][newc],newr,newc});
        //             else
        //             q.push_back({minHealth[newr][newc],newr,newc});
        //         }
        //     }
        // }
        // return false;
    }
};