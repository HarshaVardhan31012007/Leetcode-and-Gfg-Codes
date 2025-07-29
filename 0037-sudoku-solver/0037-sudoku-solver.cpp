class Solution {
public:
    bool isSafe(vector<vector<char>>&board,char digit,int row,int col,int n){
        for(int i=0;i<n;i++){
            if(board[i][col]==digit)
            return false;
        }
        for(int j=0;j<n;j++){
            if(board[row][j]==digit)
            return false;
        }
        // for(int k=0;k<n;k++){
        //     int p=3*(row/3)+k/3;
        //     int q=3*(col/3)+k%3;
        //     if(board[p][q]==digit)
        //     return false;
        // }
        int p=3*(row/3);int q=3*(col/3);
        for(int i=p;i<=p+2;i++){
            for(int j=q;j<=q+2;j++){
                if(board[i][j]==digit)
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int row,int col,int n){
        if(row==n) return true;
        int nextRow=row;int nextCol=col+1;
        if(col==n){
            nextRow=row+1;
            nextCol=0;
        }
        if(board[row][col]!='.')
        return solve(board,nextRow,nextCol,n);
        for(char digit='1';digit<='9';digit++){
            if(isSafe(board,digit,row,col,n)){
                board[row][col]=digit;
                bool nextAns=solve(board,nextRow,nextCol,n);
                if(nextAns)
                return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0,9);
    }
};