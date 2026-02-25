class Solution {
public:
    void dfs(int sr,int sc,int color,vector<vector<int>>&image,vector<vector<int>>&visited){
        visited[sr][sc]=1;
        int originalColor=image[sr][sc];
        image[sr][sc]=color;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        for(int i=0;i<4;i++){
            int x=sr+dx[i];
            int y=sc+dy[i];
            if(x<0||y<0||x>=image.size()||y>=image[0].size()) continue;
            if(image[x][y]==originalColor&&!visited[x][y]){
                dfs(x,y,color,image,visited);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>visited(image.size(),vector<int>(image[0].size(),0));
        dfs(sr,sc,color,image,visited);
        return image;
    }
};