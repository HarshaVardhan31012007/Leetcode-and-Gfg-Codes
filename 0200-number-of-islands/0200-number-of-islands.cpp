class Solution {
public:
    // void expandLand(int i,int j,vector<vector<char>>&grid,vector<vector<bool>>&visited){
    //     visited[i][j]=1;
    //     int dx[]={-1,1,0,0};
    //     int dy[]={0,0,-1,1};
    //     for(int k=0;k<4;k++){
    //         int newr=i+dx[k];
    //         int newc=j+dy[k];
    //         if(newc<0||newr<0||newr>=grid.size()||newc>=grid[0].size()) continue;
    //         if(!visited[newr][newc]&&grid[newr][newc]=='1')
    //         expandLand(newr,newc,grid,visited);
    //     }
    // }
    // int numIslands(vector<vector<char>>& grid) {
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     vector<vector<bool>>visited(m,vector<bool>(n,0));
    //     int no_of_islands=0;
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(!visited[i][j]&&grid[i][j]=='1'){
    //                expandLand(i,j,grid,visited);
    //                no_of_islands++;
    //             }
    //         }
    //     }
    //     return no_of_islands;
    // }



    void expandLand(int r,int c,vector<vector<char>>&grid,vector<vector<bool>>&visited){
        queue<pair<int,int>>q;
        q.push({r,c});
        visited[r][c]=1;
        while(!q.empty()){
            auto i=q.front().first;
            auto j=q.front().second;
            q.pop();
            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};
            for(int k=0;k<4;k++){
                int newr=i+dx[k];
                int newc=j+dy[k];
                if(newc<0||newr<0||newr>=grid.size()||newc>=grid[0].size()) continue;
                if(!visited[newr][newc]&&grid[newr][newc]=='1'){
                    visited[newr][newc]=1;
                    q.push({newr,newc});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        int no_of_islands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j]&&grid[i][j]=='1'){
                   expandLand(i,j,grid,visited);
                   no_of_islands++;
                }
            }
        }
        return no_of_islands;
    }
};