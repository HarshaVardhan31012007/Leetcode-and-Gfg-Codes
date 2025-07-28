class Solution {
public:
    // unordered_map<int,bool>rc;
    // unordered_map<int,bool>udc;
    // unordered_map<int,bool>ldc;
    // bool isSafe(int row,int col){

    //     if(rc[row]==true)
    //     return false;
    //     if(udc[row-col]==true)
    //     return false;
    //     if(ldc[row+col]==true)
    //     return false;

    //     return true;
    // }
    // void storeSolution(vector<vector<string>>&ans,vector<vector<char>>&board,int n){
    //     vector<string>temp;
    //     for(int i=0;i<n;i++){
    //         string output="";
    //         for(int j=0;j<n;j++){
    //            output.push_back(board[i][j]);
    //         }
    //         temp.push_back(output);
    //     }
    //     ans.push_back(temp);
    // }
    // void solve(vector<vector<string>>&ans,vector<vector<char>>&board,int col,int n){
    //     //base case
    //     if(col>=n){
    //       storeSolution(ans,board,n);
    //       return;
    //     }
    //     //1 case 
    //     for(int row=0;row<n;row++){
    //         //hr roe quuen place karke dekhunga
    //       if(isSafe(row,col)){
    //         board[row][col]='Q';
    //         rc[row]=true;
    //         udc[row-col]=true;
    //         ldc[row+col]=true;
    //         solve(ans,board,col+1,n);
    //         //backtracking
    //         board[row][col]='.';
    //          rc[row]=false;;
    //         udc[row-col]=false;
    //         ldc[row+col]=false;
    //       }

    //     }
    // }
    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<string>>ans;
    //     vector<vector<char>>board(n,vector<char>(n,'.'));
    //     int col=0;
    //     solve(ans,board,col,n);
    //     return ans;
    // }

    //method 2
    //best solution with using data structure

    // unordered_map<int,bool>rc;
    // unordered_map<int,bool>udc;
    // unordered_map<int,bool>ldc;
    // bool isSafe(int row,int col){

    //     if(rc[row]==true)
    //     return false;
    //     if(udc[row-col]==true)
    //     return false;
    //     if(ldc[row+col]==true)
    //     return false;

    //     return true;
    // }
    
    // void solve(vector<vector<string>>&ans,vector<string>&board,int col,int n){
    //     //base case
    //     if(col>=n){
    //       ans.push_back(board);
    //       return;
    //     }
    //     //1 case 
    //     for(int row=0;row<n;row++){
    //         //hr roe quuen place karke dekhunga
    //       if(isSafe(row,col)){
    //         board[row][col]='Q';
    //         rc[row]=true;
    //         udc[row-col]=true;
    //         ldc[row+col]=true;
    //         solve(ans,board,col+1,n);
    //         //backtracking
    //         board[row][col]='.';
    //          rc[row]=false;;
    //         udc[row-col]=false;
    //         ldc[row+col]=false;
    //       }

    //     }
    // }
    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<string>>ans;
    //     vector<string>board(n,string(n,'.'));
    //     int col=0;
    //     solve(ans,board,col,n);
    //     return ans;
    // }

    //bestt solution without using datastructure

    
    bool isSafe(vector<string>&board,int row,int col,int n){

       for(int j=0;j<n;j++){
        if(board[row][j]=='Q')
        return false;
       }

       for(int i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]=='Q')
        return false;
       }

       for(int i=row,j=col;i<n&&j>=0;i++,j--){
        if(board[i][j]=='Q')
        return false;
       }

        return true;
    }
    
    void solve(vector<vector<string>>&ans,vector<string>&board,int col,int n){
        //base case
        if(col>=n){
          ans.push_back(board);
          return;
        }
        //1 case 
        for(int row=0;row<n;row++){
            //hr roe quuen place karke dekhunga
          if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            solve(ans,board,col+1,n);
            //backtracking
            board[row][col]='.';
          }

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        int col=0;
        solve(ans,board,col,n);
        return ans;
    }
     
    //  unordered_map<int,int>rc;
    // unordered_map<int,int>udc;
    // unordered_map<int,int>ldc;
    // bool isSafe(int row,int col){

    //     if(rc[row]>=1)
    //     return false;
    //     if(udc[row-col]>=1)
    //     return false;
    //     if(ldc[row+col]>=1)
    //     return false;

    //     return true;
    // }
    // void storeSolution(vector<vector<string>>&ans,vector<vector<char>>&board,int n){
    //     vector<string>temp;
    //     for(int i=0;i<n;i++){
    //         string output="";
    //         for(int j=0;j<n;j++){
    //            output.push_back(board[i][j]);
    //         }
    //         temp.push_back(output);
    //     }
    //     ans.push_back(temp);
    // }
    // void solve(vector<vector<string>>&ans,vector<vector<char>>&board,int col,int n){
    //     //base case
    //     if(col>=n){
    //       storeSolution(ans,board,n);
    //       return;
    //     }
    //     //1 case 
    //     for(int row=0;row<n;row++){
    //         //hr roe quuen place karke dekhunga
    //       if(isSafe(row,col)){
    //         board[row][col]='Q';
    //         rc[row]++;
    //         udc[row-col]++;
    //         ldc[row+col]++;
    //         solve(ans,board,col+1,n);
    //         //backtracking
    //         board[row][col]='.';
    //          rc[row]--;
    //         udc[row-col]--;
    //         ldc[row+col]--;
    //       }

    //     }
    // }
    // vector<vector<string>> solveNQueens(int n) {
    //     vector<vector<string>>ans;
    //     vector<vector<char>>board(n,vector<char>(n,'.'));
    //     int col=0;
    //     solve(ans,board,col,n);
    //     return ans;
    // }
};