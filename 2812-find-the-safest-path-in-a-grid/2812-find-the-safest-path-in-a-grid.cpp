class Solution {
public:
    // bool possible(int i,int j,int mid,vector<vector<int>>&thiefs){
    //     for(auto &each:thiefs){
    //         int r=each[0];
    //         int c=each[1];
    //         if((abs(r-i)+abs(j-c))<mid) return false;
    //     }
    //     return true;
    // }
    // bool dfs(int i,int j,vector<vector<int>>&grid,int &n,int mid,vector<vector<int>>&thiefs,vector<vector<int>>&visited){
    //     if(i<0||j<0||i>=n||j>=n||visited[i][j]||!possible(i,j,mid,thiefs)) return false;
    //     if(i==n-1&&j==n-1) return true;
    //     visited[i][j]=1;
    //     int dx[]={-1,1,0,0};
    //     int dy[]={0,0,-1,1};
    //     for(int k=0;k<4;k++){
    //         int r=i+dx[k];
    //         int c=j+dy[k];
    //         if(dfs(r,c,grid,n,mid,thiefs,visited))
    //         return true;
    //     }
    //     return false;
    // }
    // int maximumSafenessFactor(vector<vector<int>>& grid) {
    //     vector<vector<int>>thiefs;
    //     int n=grid.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             if(grid[i][j]==1){
    //                 thiefs.push_back({i,j});
    //             }
    //         }
    //     }
    //     int s=0;
    //     int e=2*n-2;
    //     int ans;
    //     while(s<=e){
    //         int mid=s+(e-s)/2;
    //         vector<vector<int>>visited(n,vector<int>(n,0));
    //         if(dfs(0,0,grid,n,mid,thiefs,visited)){
    //             ans=mid;
    //             s=mid+1;
    //         }
    //         else{
    //             e=mid-1;
    //         }
    //     }
    //     return ans;
    // }



    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool dfs(int i,int j,vector<vector<int>>&grid,int &n,int mid,vector<vector<int>>&visited,vector<vector<int>>&dist){
        if(i<0||j<0||i>=n||j>=n||visited[i][j]||dist[i][j]<mid) return false;
        if(i==n-1&&j==n-1) return true;
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            int r=i+dx[k];
            int c=j+dy[k];
            if(dfs(r,c,grid,n,mid,visited,dist))
            return true;
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>visited(n,vector<int>(n,0));
        vector<vector<int>>dist(n,vector<int>(n,0));
        queue<vector<int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j,0});
                    visited[i][j]=1;
                    dist[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int r=q.front()[0];
            int c=q.front()[1];
            int d=q.front()[2];
            q.pop();
            for(int k=0;k<4;k++){
                int i=r+dx[k];
                int j=c+dy[k];
                if(i<0||j<0||i>=n||j>=n||visited[i][j]) continue;
                q.push({i,j,d+1});
                dist[i][j]=d+1;
                visited[i][j]=1;
            }
        }
        int s=0;
        int e=2*n-2;
        int ans;
        while(s<=e){
            int mid=s+(e-s)/2;
            vector<vector<int>>visited(n,vector<int>(n,0));
            if(dfs(0,0,grid,n,mid,visited,dist)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};