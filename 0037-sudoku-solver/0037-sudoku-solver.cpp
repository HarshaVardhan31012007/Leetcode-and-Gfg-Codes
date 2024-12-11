class Solution {
public:
    // bool isSafe(vector<vector<char>>& board,char digit,int n,int i,int j){
    //     for(int k=0;k<n;k++){
    //         if(board[i][k]==digit)
    //         return false;
    //     }
    //      for(int k=0;k<n;k++){
    //         if(board[k][j]==digit)
    //         return false;
    //     }
    
    //     for(int k=0;k<n;k++){
    //         int p=3*(i/3)+k/3;
    //         int q=3*(j/3)+k%3;
    //         if(board[p][q]==digit)
    //         return false;
    //     }
    //    return true;
    // }
    // bool solve(vector<vector<char>>& board,int n){
    //     //base case
    //     //no nested loop will stop after all iterations
    //     //no need
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<n;j++){
    //             if(board[i][j]=='.'){
    //              for(char digit='1';digit<='9';digit++){
    //                 if(isSafe(board,digit,n,i,j)){
    //                     board[i][j]=digit;
    //                     bool nextAns=solve(board,n);
    //                     if(nextAns){
    //                         return true;
    //                     }
    //                     else{
    //                         //backtrack
    //                         board[i][j]='.';
    //                     }
    //                 }
    //              }
    //             return false;
    //         }
    //     }
    // }
    // return true;
    // }
    // void solveSudoku(vector<vector<char>>& board) {
    //     int n=board.size();
    //     solve(board,n);
    // }

    bool isSafe(vector<vector<char>>& board,char digit,int i,int j){
        for(int k=0;k<9;k++){
            if(board[i][k]==digit)
            return false;
        }
         for(int k=0;k<9;k++){
            if(board[k][j]==digit)
            return false;
        }
    
            int p=3*(i/3);
            int q=3*(j/3);
            for(int t=p;t<=p+2;t++){
                for(int u=q;u<=q+2;u++){            
            if(board[t][u]==digit)
            return false;
                }
        }
       return true;
    }
    bool solve(vector<vector<char>>& board,int row,int col){
        //base case
        if(row==9)
        return true;
      int nextRow=row;int nextCol=col+1;
      if(nextCol==9){
        nextRow=row+1;
        nextCol=0;
      }

     if(board[row][col]!='.'){
        return solve(board,nextRow,nextCol);
     }
         for(char digit='1';digit<='9';digit++){
           if(isSafe(board,digit,row,col)){
          board[row][col]=digit;
             bool nextAns=solve(board,nextRow,nextCol);
               if(nextAns){
                return true;
                    }
                  //backtrack
                 board[row][col]='.';
                 
             }
          }
                return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int row=0;
        int col=0;
        solve(board,row,col);
    }
};