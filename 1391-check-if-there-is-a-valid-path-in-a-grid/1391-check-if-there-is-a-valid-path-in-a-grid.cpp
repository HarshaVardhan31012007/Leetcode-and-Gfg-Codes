// class Solution {
// public:
//     // bool connects_south(vector<vector<int>>&grid,int x,int y){
//     //     return grid[x][y]==2||grid[x][y]==5||grid[x][y]==6;
//     // }
//     // bool connects_north(vector<vector<int>>&grid,int x,int y){
//     //     return grid[x][y]==2||grid[x][y]==3||grid[x][y]==4;
//     // }
//     // bool connects_west(vector<vector<int>>&grid,int x,int y){
//     //     return grid[x][y]==1||grid[x][y]==4||grid[x][y]==6;
//     // }
//     // bool connects_east(vector<vector<int>>&grid,int x,int y){
//     //     return grid[x][y]==1||grid[x][y]==3||grid[x][y]==5;
//     // }
//     bool solve(vector<vector<int>>&grid,int i,int j,int m,int n,vector<vector<int>>&visited){
//         if(i==m-1&&j==n-1) return true;
//         visited[i][j]=1;
//         if(grid[i][j]==1){
//             int x1=i;int y1=j-1;
//             if(y1>=0&&!visited[x1][y1]&&(grid[x1][y1]==1||grid[x1][y1]==4||grid[x1][y1]==6)){
//                if(solve(grid,x1,y1,m,n,visited))
//                return true;
//             }
//             x1=i;y1=j+1;
//             if(y1<n&&!visited[x1][y1]&&(grid[x1][y1]==1||grid[x1][y1]==3||grid[x1][y1]==5)){
//                if(solve(grid,x1,y1,m,n,visited))
//                return true;
//             }
//         }
//         else if(grid[i][j]==2){
//             int x1=i-1;int y1=j;
//             if(x1>=0&&!visited[x1][y1]&&(grid[x1][y1]==2||grid[x1][y1]==3||grid[x1][y1]==4)){
//                if(solve(grid,x1,y1,m,n,visited))
//                return true;
//             }
//             x1=i+1;y1=j;
//             if(x1<m&&!visited[x1][y1]&&(grid[x1][y1]==2||grid[x1][y1]==5||grid[x1][y1]==6)){
//                if(solve(grid,x1,y1,m,n,visited))
//                return true;
//             }
//         }
//         else if(grid[i][j]==3){
//             int x1=i;int y1=j-1;
//             if(y1>=0&&!visited[x1][y1]&&(grid[x1][y1]==1||grid[x1][y1]==4||grid[x1][y1]==6)){
//                if(solve(grid,x1,y1,m,n,visited))
//                return true;
//             }
//             x1=i+1;y1=j;
//             if(x1<m&&!visited[x1][y1]&&(grid[x1][y1]==2||grid[x1][y1]==5||grid[x1][y1]==6)){
//                if(solve(grid,x1,y1,m,n,visited))
//                return true;
//             }
//         }
//         else if(grid[i][j]==4){
//             int x1=i;int y1=j+1;
//             if(y1<n&&!visited[x1][y1]&&(grid[x1][y1]==1||grid[x1][y1]==3||grid[x1][y1]==5)){
//                if(solve(grid,x1,y1,m,n,visited))
//                return true;
//             }
//             x1=i+1;y1=j;
//             if(x1<m&&!visited[x1][y1]&&(grid[x1][y1]==2||grid[x1][y1]==5||grid[x1][y1]==6)){
//                if(solve(grid,x1,y1,m,n,visited))
//                return true;
//             }
//         }
//         else if(grid[i][j]==5){
//             int x1=i-1;int y1=j;
//             if(x1>=0&&!visited[x1][y1]&&(grid[x1][y1]==2||grid[x1][y1]==3||grid[x1][y1]==4)){
//                if(solve(grid,x1,y1,m,n,visited))
//                return true;
//             }
//             x1=i;y1=j-1;
//             if(y1>=0&&!visited[x1][y1]&&(grid[x1][y1]==1||grid[x1][y1]==4||grid[x1][y1]==6)){
//                if(solve(grid,x1,y1,m,n,visited))
//                return true;
//             }
//         }
//         else if(grid[i][j]==6){
//             int x1=i-1;int y1=j;
//             if(x1>=0&&!visited[x1][y1]&&(grid[x1][y1]==2||grid[x1][y1]==3||grid[x1][y1]==4)){
//                if(solve(grid,x1,y1,m,n,visited))
//                return true;
//             }
//             x1=i;y1=j+1;
//             if(y1<n&&!visited[x1][y1]&&(grid[x1][y1]==1||grid[x1][y1]==3||grid[x1][y1]==5)){
//                if(solve(grid,x1,y1,m,n,visited))
//                return true;
//             }
//         }
//         return false;
//     }
//     bool hasValidPath(vector<vector<int>>& grid) {
//         int m=grid.size();int n=grid[0].size();
//         vector<vector<int>>visited(m,vector<int>(n,0));
//         return solve(grid,0,0,m,n,visited);
//     }
// };






class Solution {
public:
    vector<vector<vector<int>>>dirs={
        {{0,-1},{0,1}},
        {{-1,0},{1,0}},
        {{0,-1},{1,0}},
        {{0,1},{1,0}},
        {{0,-1},{-1,0}},
        {{-1,0},{0,1}}
    };
    bool solve(vector<vector<int>>&grid,int i,int j,int m,int n,vector<vector<int>>&visited){
        if(i==m-1&&j==n-1) return true;
        visited[i][j]=1;
        for(auto &each:dirs[grid[i][j]-1]){
            int x=i+each[0];
            int y=j+each[1];
            if(x<0||y<0||x>=m||y>=n||visited[x][y]) continue;
            for(auto &each1:dirs[grid[x][y]-1]){
                int x1=x+each1[0];
                int y1=y+each1[1];
                if(x1==i&&y1==j&&solve(grid,x,y,m,n,visited)){
                   return true;
                }
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size();int n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        return solve(grid,0,0,m,n,visited);
    }
};