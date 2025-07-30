// class Solution {
// public:
//     bool isSafe(vector<vector<char>>&board,string &word,vector<vector<bool>>&visited,int i,int row,int col){
//         if(row<0||col<0||row>=board.size()||col>=board[0].size())
//         return false;
//         if(visited[row][col]==true)
//         return false;
//         if(word[i]!=board[row][col])
//         return false;
//         return true;
//     }
//     bool solve(vector<vector<char>>&board,string &word,vector<vector<bool>>&visited,int i,int row,int col){
//         if(i==word.size()) return true;
//         int dx[]={0,0,-1,1};
//         int dy[]={-1,1,0,0};
//         for(int k=0;k<4;k++){
//             int newRow=row+dx[k];
//             int newCol=col+dy[k];
//             if(isSafe(board,word,visited,i,newRow,newCol)){
//                  visited[newRow][newCol]=1;
//                  bool ans=solve(board,word,visited,i+1,newRow,newCol);
//                  if(ans) return true;
//                  visited[newRow][newCol]=0;
//             }
//         }
//         return false;
//     }
//     bool exist(vector<vector<char>>& board, string word) {
//         vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),0));    
//          for(int row=0;row<board.size();row++){
//             for(int col=0;col<board[0].size();col++){
//                    if(board[row][col]==word[0]){
//                       visited[row][col]=1;
//                       bool ans=solve(board,word,visited,1,row,col);
//                       if(ans) return true;
//                       visited[row][col]=0;
//                    }
//             }
//         }
//         return false;
//     }
// };





//No need of visited 2d array 
//In the same 2d array do replace with one value and store actual value in temp variable
// so that when youa re backtracking you can repalce it

class Solution {
public:
    bool isSafe(vector<vector<char>>&board,string &word,int i,int row,int col){
        if(row<0||col<0||row>=board.size()||col>=board[0].size())
        return false;
        if(board[row][col]=='%')
        return false;
        if(word[i]!=board[row][col])
        return false;
        return true;
    }
    bool solve(vector<vector<char>>&board,string &word,int i,int row,int col){
        if(i==word.size()) return true;
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        for(int k=0;k<4;k++){
            int newRow=row+dx[k];
            int newCol=col+dy[k];
            if(isSafe(board,word,i,newRow,newCol)){
                 char temp=board[row][col];
                 board[row][col]='%';
                 bool ans=solve(board,word,i+1,newRow,newCol);
                 if(ans) return true;
                 board[row][col]=temp;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
         for(int row=0;row<board.size();row++){
            for(int col=0;col<board[0].size();col++){
                   if(board[row][col]==word[0]){
                      char temp=board[row][col];
                      board[row][col]='%';
                      bool ans=solve(board,word,1,row,col);
                      if(ans) return true;
                      board[row][col]=temp;
                   }
            }
        }
        return false;
    }
};