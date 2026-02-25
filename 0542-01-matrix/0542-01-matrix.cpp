class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    ans[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int r=front.first;
            int c=front.second;
            int dx[4]={-1,1,0,0};
            int dy[4]={0,0,-1,1};
            for(int j=0;j<4;j++){
                int x=r+dx[j];
                int y=c+dy[j];
                if(x<0||y<0||x>=m||y>=n) continue;
                if(ans[x][y]==INT_MAX){
                    ans[x][y]=1+ans[r][c];
                    q.push({x,y});
                }
            }
        }
        return ans;
    }
};