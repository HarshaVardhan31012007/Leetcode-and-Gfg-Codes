class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& board,vector<vector<int>>&visited){
        visited[r][c]=1;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0;i<4;i++){
           int x=r+dx[i];
           int y=c+dy[i];
           if(x<0||y<0||x>=board.size()||y>=board[0].size()) continue;
           if(!visited[x][y]&&board[x][y]=='O')
           dfs(x,y,board,visited);
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();int n=board[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'&&!visited[i][0]){
                dfs(i,0,board,visited);
            }
            if(board[i][n-1]=='O'&&!visited[i][n-1]){
                dfs(i,n-1,board,visited);
            }
        }
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'&&!visited[0][i]){
                dfs(0,i,board,visited);
            }
            if(board[m-1][i]=='O'&&!visited[m-1][i]){
                dfs(m-1,i,board,visited);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((!visited[i][j])&&board[i][j]=='O')
                board[i][j]='X';
            }
        }
    }
};