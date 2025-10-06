class Solution {
public:
    // void solve(vector<vector<int>>&grid,vector<vector<int>>&visited,int i,int j,int &ans,int t,int &n){
    //        if(i==n-1&&j==n-1){
    //           ans=min(ans,t);
    //           return;
    //        }
    //        if(t>=ans) return;
    //        visited[i][j]=1;
    //        int dx[]={1,0,0,-1};
    //        int dy[]={0,1,-1,0};
    //        for(int k=0;k<4;k++){
    //            int x=i+dx[k];
    //            int y=j+dy[k];
    //            if(x>=0&&x<n&&y>=0&&y<n&&!visited[x][y]&&grid[i][j]<ans){
    //               solve(grid,visited,x,y,ans,max(t,grid[x][y]),n);
    //            }
    //        }
    //        visited[i][j]=0;
    // }
    // int swimInWater(vector<vector<int>>& grid) {
    //     int ans=INT_MAX;
    //     int n=grid.size();
    //     vector<vector<int>>visited(n,vector<int>(n,0));
    //     solve(grid,visited,0,0,ans,grid[0][0],n);
    //     return ans;
    // }




    // typedef pair<int,pair<int,int>>PP;
    // int swimInWater(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     vector<vector<int>>time(n,vector<int>(n,INT_MAX));
    //     time[0][0]=grid[0][0];
    //     priority_queue<PP,vector<PP>,greater<>>pq;
    //     pq.push({time[0][0],{0,0}});
    //     while(!pq.empty()){
    //         auto top=pq.top();
    //         pq.pop();
    //         int currtime=top.first;
    //         int x=top.second.first;
    //         int y=top.second.second;
    //         int dx[]={-1,1,0,0};
    //         int dy[]={0,0,-1,1};
    //         for(int i=0;i<4;i++){
    //             int newx=x+dx[i];
    //             int newy=y+dy[i];
    //             if(newx>=0&&newx<n&&newy>=0&&newy<n&&max(currtime,grid[newx][newy])<time[newx][newy]){
    //                 time[newx][newy]=max(currtime,grid[newx][newy]);
    //                 pq.push({time[newx][newy],{newx,newy}});
    //             }
    //         }
    //     }
    //     return time[n-1][n-1];
    // }



    void dfs(vector<vector<int>>& grid,vector<vector<int>>&visited,int i,int j,int &n,int &time){
       visited[i][j]=1;
       int dx[]={-1,1,0,0};
       int dy[]={0,0,-1,1};
       for(int k=0;k<4;k++){
          int x=i+dx[k];
          int y=j+dy[k];
          if(x>=0&&x<n&&y>=0&&y<n&&!visited[x][y]&&grid[x][y]<=time){
            dfs(grid,visited,x,y,n,time);
          }
       }
    }
    int swimInWater(vector<vector<int>>& grid) {
        int i=grid[0][0];
       // int j=50*50-1;//actually j is max element of grid
       int maxi=INT_MIN;
       for(auto &row:grid){
        for(auto &ele:row){
          maxi=max(maxi,ele);
        }
       }
       int j=maxi;
        int ans=-1;
        int n=grid.size();
        while(i<=j){
            int mid=i+(j-i)/2;
            vector<vector<int>>visited(n,vector<int>(n,0));
            dfs(grid,visited,0,0,n,mid);// to make visited you can also use bfs
            if(visited[n-1][n-1]){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};