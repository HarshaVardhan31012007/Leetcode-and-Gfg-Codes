class Solution {
public:
void markSameIsland(vector<vector<char>>&grid,int r,int c){
    if(r<0||r>=grid.size()||c<0||c>=grid[0].size()||grid[r][c]=='0'){
        return;
    }
    grid[r][c]='0';
    
    markSameIsland(grid,r,c-1);
    markSameIsland(grid,r-1,c);
    markSameIsland(grid,r+1,c);
    markSameIsland(grid,r,c+1);
}
 int solve(vector<vector<char>>&grid){
    int n=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='1'){
                markSameIsland(grid,i,j);
                n++;
            }
        }
    }
    return n;
 }
    int numIslands(vector<vector<char>>& grid) {
       return solve(grid);
    }
};