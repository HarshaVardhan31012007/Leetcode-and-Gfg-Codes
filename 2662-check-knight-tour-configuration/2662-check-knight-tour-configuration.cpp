class Solution {
public:
    bool solve(vector<vector<int>>& grid,int row,int col,int count){
     //   if(count==(grid.size()*grid.size())) return true;
        if(row<0||col<0||row>=grid.size()||col>=grid[0].size()||grid[row][col]==-1||grid[row][col]!=count) return false;
        if(count==(grid.size()*grid.size()-1)) return true;
        //visited no need ad grid[row][col]!=count take care of it
        // int temp=grid[row][col];
        // grid[row][col]=-1;
        bool ans=solve(grid,row+1,col+2,count+1)||solve(grid,row-1,col+2,count+1)||solve(grid,row+2,col+1,count+1)||solve(grid,row-2,col+1,count+1)||solve(grid,row+2,col-1,count+1)||solve(grid,row-2,col-1,count+1)||solve(grid,row+1,col-2,count+1)||solve(grid,row-1,col-2,count+1);
        //grid[row][col]=temp;
        return ans;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int row=0;int col=0;int count=0;
        bool ans=solve(grid,row,col,count);
        return ans;
    }
};