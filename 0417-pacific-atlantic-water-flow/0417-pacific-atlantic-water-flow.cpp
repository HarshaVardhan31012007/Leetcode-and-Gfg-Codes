class Solution {
public:
    //   void check(vector<vector<int>>&heights,int i,int j,vector<vector<int>>&visited,bool &flag,bool &flag1){
    //      if(visited[i][j]) return;
    //      if(i==0||j==0){
    //         flag=true;
    //      }
    //      if(i==heights.size()-1||j==heights[0].size()-1){
    //         flag1=true;
    //      }
    //      if(flag&&flag1) return;
    //      visited[i][j]=true;
    //      if(i-1>=0&&heights[i-1][j]<=heights[i][j])
    //      check(heights,i-1,j,visited,flag,flag1);
    //      if(i+1<heights.size()&&heights[i+1][j]<=heights[i][j])
    //      check(heights,i+1,j,visited,flag,flag1);
    //      if(j-1>=0&&heights[i][j-1]<=heights[i][j])
    //      check(heights,i,j-1,visited,flag,flag1);
    //      if(j+1<heights[0].size()&&heights[i][j+1]<=heights[i][j])
    //      check(heights,i,j+1,visited,flag,flag1);
    //      visited[i][j]=false;
    // }
    // vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    //     vector<vector<int>>ans;
    //     for(int i=0;i<heights.size();i++){
    //         for(int j=0;j<heights[0].size();j++){
    //             vector<vector<int>>visited(heights.size(),vector<int>(heights[0].size(),0));bool flag=0;bool flag1=0;
    //             check(heights,i,j,visited,flag,flag1);
    //             if(flag&&flag1){
    //                 ans.push_back({i,j});
    //             }
    //         }
    //     }
    //     return ans;
    //}


    // vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    //        queue<pair<int,pair<int,int>>>q;
    //        queue<pair<int,pair<int,int>>>q1;
    //        int m=heights.size();
    //        int n=heights[0].size();
    //        vector<vector<bool>>pacific(m,vector<bool>(n,0));
    //        vector<vector<bool>>atlantic(m,vector<bool>(n,0));
    //        vector<vector<int>>ans;
    //        for(int row=0;row<m;row++){
    //               q.push({heights[row][0],{row,0}});
    //               pacific[row][0]=true;
    //               q1.push({heights[row][n-1],{row,n-1}});
    //               atlantic[row][n-1]=true;
    //        }
    //        q1.push({heights[m-1][0],{m-1,0}});
    //        atlantic[m-1][0]=true;
    //        q.push({heights[0][n-1],{0,n-1}});
    //        pacific[0][n-1]=true;
    //        for(int col=1;col<n-1;col++){
    //           q.push({heights[0][col],{0,col}});
    //           pacific[0][col]=true;
    //           q1.push({heights[m-1][col],{m-1,col}});
    //           atlantic[m-1][col]=true;
    //        }
    //        while(!q.empty()){
    //             auto front=q.front();
    //             q.pop();
    //             int height=front.first;
    //             int x=front.second.first;
    //             int y=front.second.second;
    //             int dx[]={-1,1,0,0};
    //             int dy[]={0,0,-1,1};
    //             for(int i=0;i<4;i++){
    //                 int newx=x+dx[i];
    //                 int newy=y+dy[i];
    //                 if(newx>=0&&newx<m&&newy>=0&&newy<n&&!pacific[newx][newy]&&heights[newx][newy]>=height){
    //                     pacific[newx][newy]=true;
    //                     q.push({heights[newx][newy],{newx,newy}});
    //                 }
    //             }
    //        }

    //         while(!q1.empty()){
    //             auto front=q1.front();
    //             q1.pop();
    //             int height=front.first;
    //             int x=front.second.first;
    //             int y=front.second.second;
    //             int dx[]={-1,1,0,0};
    //             int dy[]={0,0,-1,1};
    //             for(int i=0;i<4;i++){
    //                 int newx=x+dx[i];
    //                 int newy=y+dy[i];
    //                 if(newx>=0&&newx<m&&newy>=0&&newy<n&&!atlantic[newx][newy]&&heights[newx][newy]>=height){
    //                     atlantic[newx][newy]=true;
    //                     q1.push({heights[newx][newy],{newx,newy}});
    //                 }
    //             }
    //        }
    //        for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(pacific[i][j]&&atlantic[i][j])
    //             ans.push_back({i,j});
    //         }
    //        }
    //        return ans;
    // }




    // vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    //        queue<pair<int,pair<int,int>>>q;
    //        queue<pair<int,pair<int,int>>>q1;
    //        int m=heights.size();
    //        int n=heights[0].size();
    //        vector<vector<bool>>pacific(m,vector<bool>(n,0));
    //        vector<vector<bool>>atlantic(m,vector<bool>(n,0));
    //        vector<vector<int>>ans;
    //        for(int row=0;row<m;row++){
    //               q.push({heights[row][0],{row,0}});
    //               pacific[row][0]=true;
    //               q1.push({heights[row][n-1],{row,n-1}});
    //               atlantic[row][n-1]=true;
    //               //edge case
    //               if(n==1)
    //               ans.push_back({row,0});
    //        }
    //        //edge case
    //        if(n==1) return ans;
    //        //important
    //        if(m!=1&&n!=1){
    //        q.push({heights[0][n-1],{0,n-1}});
    //        pacific[0][n-1]=true;
    //        q1.push({heights[m-1][0],{m-1,0}});
    //        atlantic[m-1][0]=true;
    //        ans.push_back({m-1,0});
    //        ans.push_back({0,n-1});
    //        }
    //        for(int col=1;col<n-1;col++){
    //           q.push({heights[0][col],{0,col}});
    //           pacific[0][col]=true;
    //           q1.push({heights[m-1][col],{m-1,col}});
    //           atlantic[m-1][col]=true;
    //           //edge case
    //           if(m==1){
    //              ans.push_back({0,col});
    //           }
    //        }
    //        //edge case
    //        if(m==1){
    //         ans.push_back({0,0});
    //         if(n!=1)
    //         ans.push_back({0,n-1});
    //         return ans;
    //        }
    //        while(!q.empty()){
    //             auto front=q.front();
    //             q.pop();
    //             int height=front.first;
    //             int x=front.second.first;
    //             int y=front.second.second;
    //             int dx[]={-1,1,0,0};
    //             int dy[]={0,0,-1,1};
    //             for(int i=0;i<4;i++){
    //                 int newx=x+dx[i];
    //                 int newy=y+dy[i];
    //                 if(newx>=0&&newx<m&&newy>=0&&newy<n&&!pacific[newx][newy]&&heights[newx][newy]>=height){
    //                     pacific[newx][newy]=true;
    //                     if(atlantic[newx][newy]==true)
    //                     ans.push_back({newx,newy});
    //                     q.push({heights[newx][newy],{newx,newy}});
    //                 }
    //             }
    //        }

    //         while(!q1.empty()){
    //             auto front=q1.front();
    //             q1.pop();
    //             int height=front.first;
    //             int x=front.second.first;
    //             int y=front.second.second;
    //             int dx[]={-1,1,0,0};
    //             int dy[]={0,0,-1,1};
    //             for(int i=0;i<4;i++){
    //                 int newx=x+dx[i];
    //                 int newy=y+dy[i];
    //                 if(newx>=0&&newx<m&&newy>=0&&newy<n&&!atlantic[newx][newy]&&heights[newx][newy]>=height){
    //                     atlantic[newx][newy]=true;
    //                     if(pacific[newx][newy]==true)
    //                     ans.push_back({newx,newy});
    //                     q1.push({heights[newx][newy],{newx,newy}});
    //                 }
    //             }
    //        }
    //        return ans;
    // }












    //  void bfs(queue<pair<int,pair<int,int>>>&q,vector<vector<int>>& heights,vector<vector<bool>>&visited,int m,int n){
    //         while(!q.empty()){
    //             auto front=q.front();
    //             q.pop();
    //             int height=front.first;
    //             int x=front.second.first;
    //             int y=front.second.second;
    //             int dx[]={-1,1,0,0};
    //             int dy[]={0,0,-1,1};
    //             for(int i=0;i<4;i++){
    //                 int newx=x+dx[i];
    //                 int newy=y+dy[i];
    //                 if(newx>=0&&newx<m&&newy>=0&&newy<n&&!visited[newx][newy]&&heights[newx][newy]>=height){
    //                     visited[newx][newy]=true;
    //                     q.push({heights[newx][newy],{newx,newy}});
    //                 }
    //             }
    //        }
    //  }
    //  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    //        int m=heights.size();
    //        int n=heights[0].size();
    //        vector<vector<bool>>pacific(m,vector<bool>(n,0));
    //        vector<vector<bool>>atlantic(m,vector<bool>(n,0));
    //        queue<pair<int,pair<int,int>>>q;

    //        for(int i=0;i<m;i++){
    //             q.push({heights[i][0],{i,0}});
    //             pacific[i][0]=true;
    //        }
    //        for(int j=0;j<n;j++){
    //             q.push({heights[0][j],{0,j}});
    //             pacific[0][j]=true;
    //        }
    //        bfs(q,heights,pacific,m,n);

    //        for(int i=0;i<m;i++){
    //             q.push({heights[i][n-1],{i,n-1}});
    //             atlantic[i][n-1]=true;
    //        }
    //        for(int j=0;j<n;j++){
    //             q.push({heights[m-1][j],{m-1,j}});
    //             atlantic[m-1][j]=true;
    //        }
    //        bfs(q,heights,atlantic,m,n);

    //        vector<vector<int>>ans;
    //        for(int i=0;i<m;i++){
    //             for(int j=0;j<n;j++){
    //                 if(pacific[i][j]&&atlantic[i][j])
    //                 ans.push_back({i,j});
    //             }
    //        }
    //        return ans;
    // }




     void dfs(vector<vector<int>>& heights,vector<vector<bool>>&visited,int i,int j)  {
             visited[i][j]=true;
                int dx[]={-1,1,0,0};
                int dy[]={0,0,-1,1};
                for(int k=0;k<4;k++){
                    int newx=i+dx[k];
                    int newy=j+dy[k];
                    if(newx>=0&&newx<heights.size()&&newy>=0&&newy<heights[0].size()&&!visited[newx][newy]&&heights[newx][newy]>=heights[i][j]){
                        dfs(heights,visited,newx,newy);
                    }
                }
     }
     vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
           int m=heights.size();
           int n=heights[0].size();
           vector<vector<bool>>pacific(m,vector<bool>(n,0));
           vector<vector<bool>>atlantic(m,vector<bool>(n,0));

           for(int i=0;i<m;i++){
               dfs(heights,pacific,i,0);
               dfs(heights,atlantic,i,n-1);
           }
           for(int j=0;j<n;j++){
               dfs(heights,pacific,0,j);
               dfs(heights,atlantic,m-1,j);
           }

           vector<vector<int>>ans;
           for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(pacific[i][j]&&atlantic[i][j])
                    ans.push_back({i,j});
                }
           }
           return ans;
    }
};