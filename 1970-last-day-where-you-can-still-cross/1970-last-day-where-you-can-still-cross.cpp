class Solution {
public:
    // bool dfs(int i,int j,int day,vector<vector<int>>&v,vector<vector<int>>&visited){
    //     if(i<0||j<0||i>=v.size()||j>=v[0].size()||v[i][j]<=day||visited[i][j])
    //     return false;
    //     if(i==v.size()-1) return true;
    //     visited[i][j]=true;
    //     bool ans=false;
    //     int dx[4]={-1,1,0,0};
    //     int dy[4]={0,0,-1,1};
    //     for(int k=0;k<4;k++){
    //         int x=i+dx[k];int y=j+dy[k];
    //         ans=ans||dfs(x,y,day,v,visited);
    //     }
    //     return ans;
    // }
    // bool possible(vector<vector<int>>&v,int day){
    //     vector<vector<int>>visited(v.size(),vector<int>(v[0].size(),0));
    //     bool ans=false;
    //     for(int j=0;j<v[0].size();j++){
    //          if(!visited[0][j]){
    //             ans=ans||dfs(0,j,day,v,visited);
    //          }
    //     }
    //     return ans;
    // }
    // int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    //     vector<vector<int>>v(row,vector<int>(col,0));
    //     for(int i=0;i<cells.size();i++){
    //         v[cells[i][0]-1][cells[i][1]-1]=i+1;
    //     }
    //     int s=0;
    //     int e=row*(col-1);
    //     int ans=0;
    //     while(s<=e){
    //         int mid=s+(e-s)/2;
    //         if(possible(v,mid)){
    //             ans=mid;
    //             s=mid+1;
    //         }
    //         else{
    //             e=mid-1;
    //         }
    //     }
    //     return ans;
    // }



    //  bool bfs(int i,int j,int day,vector<vector<int>>&v,vector<vector<int>>&visited){
    //     if(i<0||j<0||i>=v.size()||j>=v[0].size()||v[i][j]<=day||visited[i][j])
    //     return false;
    //     queue<pair<int,int>>q;
    //     q.push({i,j});
    //     visited[i][j]=true;
    //     while(!q.empty()){
    //         auto front=q.front();
    //         q.pop();
    //         if(front.first==v.size()-1) return true;
    //         int dx[4]={-1,1,0,0};
    //         int dy[4]={0,0,-1,1};
    //         for(int k=0;k<4;k++){
    //             int x=front.first+dx[k];int y=front.second+dy[k];
    //             if(x>=0&&x<v.size()&&y>=0&&y<v[0].size()&&!visited[x][y]&&v[x][y]>day){   
    //                 q.push({x,y});
    //                 visited[x][y]=true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    // bool possible(vector<vector<int>>&v,int day){
    //     vector<vector<int>>visited(v.size(),vector<int>(v[0].size(),0));
    //     bool ans=false;
    //     for(int j=0;j<v[0].size();j++){
    //          if(!visited[0][j]){
    //             ans=ans||bfs(0,j,day,v,visited);
    //          }
    //     }
    //     return ans;
    // }
    // int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    //     vector<vector<int>>v(row,vector<int>(col,0));
    //     for(int i=0;i<cells.size();i++){
    //         v[cells[i][0]-1][cells[i][1]-1]=i+1;
    //     }
    //     int s=0;
    //     int e=row*(col-1);
    //     int ans=0;
    //     while(s<=e){
    //         int mid=s+(e-s)/2;
    //         if(possible(v,mid)){
    //             ans=mid;
    //             s=mid+1;
    //         }
    //         else{
    //             e=mid-1;
    //         }
    //     }
    //     return ans;
    // }




    // bool dfs(int i,int j,int day,vector<vector<int>>&visited){
    //     if(i<0||j<0||i>=visited.size()||j>=visited[0].size()||visited[i][j])
    //     return false;
    //     if(i==visited.size()-1) return true;
    //     visited[i][j]=true;
    //     bool ans=false;
    //     int dx[4]={-1,1,0,0};
    //     int dy[4]={0,0,-1,1};
    //     for(int k=0;k<4;k++){
    //         int x=i+dx[k];int y=j+dy[k];
    //         ans=ans||dfs(x,y,day,visited);
    //     }
    //     return ans;
    // }
    // bool possible(vector<vector<int>>&cells,int row,int col,int day){
    //     bool ans=false;
    //     vector<vector<int>>visited(row,vector<int>(col,0));
    //     for(int i=0;i<day;i++){
    //         visited[cells[i][0]-1][cells[i][1]-1]=1;
    //     }
    //     for(int j=0;j<col;j++){
    //          if(!visited[0][j]){
    //             ans=ans||dfs(0,j,day,visited);
    //          }
    //     }
    //     return ans;
    // }
    // int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
    //     int s=0;
    //     int e=row*(col-1);
    //     int ans=0;
    //     while(s<=e){
    //         int mid=s+(e-s)/2;
    //         if(possible(cells,row,col,mid)){
    //             ans=mid;
    //             s=mid+1;
    //         }
    //         else{
    //             e=mid-1;
    //         }
    //     }
    //     return ans;
    // }


   
    bool possible(vector<vector<int>>&cells,int row,int col,int day){
        vector<vector<int>>visited(row,vector<int>(col,0));
        queue<pair<int,int>>q;
        for(int i=0;i<day;i++){
            visited[cells[i][0]-1][cells[i][1]-1]=1;
        }
        for(int j=0;j<col;j++){
            if(!visited[0][j]){
               q.push({0,j});
               visited[0][j]=1;
            }
        }
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            if(front.first==row-1) return true;
            int dx[4]={-1,1,0,0};
            int dy[4]={0,0,-1,1};
            for(int k=0;k<4;k++){
                int x=front.first+dx[k];int y=front.second+dy[k];
                if(x>=0&&x<row&&y>=0&&y<col&&!visited[x][y]){   
                    q.push({x,y});
                    visited[x][y]=true;
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int s=0;
        int e=row*(col-1);
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(cells,row,col,mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }


};