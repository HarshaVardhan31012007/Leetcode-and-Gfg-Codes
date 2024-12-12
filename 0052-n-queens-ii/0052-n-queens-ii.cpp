class Solution {
public:
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
    
    void solve(vector<string>&board,int col,int n,int &count){
        //base case
        if(col>=n){
          count++;
          return;
        }
        //1 case 
        for(int row=0;row<n;row++){
            //hr roe quuen place karke dekhunga
          if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            solve(board,col+1,n,count);
            //backtracking
            board[row][col]='.';
          }

        }
    }
     
    int totalNQueens(int n) {
        vector<string>board(n,string(n,'.'));
        int count=0;
        int col=0;
        solve(board,col,n,count);
        return count;
    }
};