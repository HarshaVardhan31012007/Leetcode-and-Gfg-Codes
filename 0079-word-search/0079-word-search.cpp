class Solution {
public:
    bool solve(vector<vector<char>>& board, string word,int row,int col,int k){
        //base case
        if(k==word.size()){
            return true;
        }
        if(row<0||col<0||row>=board.size()||col>=board[0].size()||board[row][col]!=word[k])
        return false;//board[row][col]!='%' no need 
       //up to this reached means word[i] match hua
       //visited
       char temp=board[row][col];
       board[row][col]='%';
       //recursive call
       int dx[]={-1,1,0,0};
       int dy[]={0,0,-1,1};
    //    bool found=0;
    //    for(int i=0;i<4;i++){
    //     found=found||solve(board,word,row+dx[i],col+dy[i],k+1);
    //    }
    bool found=solve(board,word,row+1,col,k+1)||solve(board,word,row,col+1,k+1)||solve(board,word,row-1,col,k+1)||solve(board,word,row,col-1,k+1);

       //unvisit
       board[row][col]=temp;

     return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(solve(board,word,i,j,0))
                return true;
            }
        }
        return false;
    }
};