class Solution {
public:
    unordered_map<int,bool>rc;
    unordered_map<int,bool>udc;
    unordered_map<int,bool>ldc;
    bool isSafe(int row,int col){

        if(rc[row]==true)
        return false;
        if(udc[row-col]==true)
        return false;
        if(ldc[row+col]==true)
        return false;

        return true;
    }
    void storeSolution(vector<vector<string>>&ans,vector<vector<char>>&board,int n){
        vector<string>temp;
        for(int i=0;i<n;i++){
            string output="";
            for(int j=0;j<n;j++){
               output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }
    void solve(vector<vector<string>>&ans,vector<vector<char>>&board,int col,int n){
        //base case
        if(col>=n){
          storeSolution(ans,board,n);
          return;
        }
        //1 case 
        for(int row=0;row<n;row++){
            //hr roe quuen place karke dekhunga
          if(isSafe(row,col)){
            board[row][col]='Q';
            rc[row]=true;
            udc[row-col]=true;
            ldc[row+col]=true;
            solve(ans,board,col+1,n);
            //backtracking
            board[row][col]='.';
             rc[row]=false;;
            udc[row-col]=false;
            ldc[row+col]=false;
          }

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>>board(n,vector<char>(n,'.'));
        int col=0;
        solve(ans,board,col,n);
        return ans;
    }
};