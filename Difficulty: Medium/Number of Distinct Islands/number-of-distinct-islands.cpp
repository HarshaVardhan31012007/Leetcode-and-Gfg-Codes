// User function Template for C++

class Solution {
  public:
    string dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&visited){
        visited[i][j]=1;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        char ch[]={'U','D','L','R'};
        string path="";
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            char curr=ch[k];
            if(x<0||y<0||x>=grid.size()||y>=grid[0].size()) {
               continue;
            }
            if(!visited[x][y]&&grid[x][y]==1){
                string reccall=dfs(x,y,grid,visited);
                reccall="("+reccall+")";
                path+=curr+reccall;
            }
        }
        return path;
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string>st;
        int m=grid.size();int n=grid[0].size();int ans=0;
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(!visited[i][j]&&grid[i][j]==1){
                     string path=dfs(i,j,grid,visited);
                     if(!st.count(path)){
                         ans++;
                         st.insert(path);
                     }
                 }
            }
        }
        return ans;
    }
};
