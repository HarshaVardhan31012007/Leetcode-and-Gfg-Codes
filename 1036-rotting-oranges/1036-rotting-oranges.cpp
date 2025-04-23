// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         vector<int>rotten;
//         vector<int>v;
//         unordered_map<int,list<int>>graph;
//         int c=grid[0].size();int n=grid.size();
//         for(int i=0;i<grid.size();i++){
//             for(int j=0;j<grid[i].size();j++){
//                 if(grid[i][j]==0) continue;
//                 if(grid[i][j]==2) rotten.push_back(c*i+j);
//                  v.push_back(c*i+j);
//                  if(i-1>=0&&grid[i-1][j]!=0)
//                  graph[c*i+j].push_back(c*(i-1)+j);
//                  if(i+1<n&&grid[i+1][j]!=0)
//                  graph[c*i+j].push_back(c*(i+1)+j);
//                  if(j-1>=0&&grid[i][j-1]!=0)
//                   graph[c*i+j].push_back(c*i+j-1);
//                   if(j+1<c&&grid[i][j+1]!=0)
//                   graph[c*i+j].push_back(c*i+j+1);
//                  }
//             }
//         unordered_map<int,bool>visited;
//         queue<int>q;
//         int count=0;
//         for (auto &each:rotten){
//           q.push(each);
//           visited[each]=true;
//         }
//         while(!q.empty()){
//             int size=q.size();
//             bool a=0;
//             for(int i=0;i<size;i++){
//               auto front=q.front();
//               q.pop();
//               for(auto &each:graph[front]){
//                 if(!visited[each]){
//                     visited[each]=true;
//                     q.push(each);
//                     a=1;
//                 }
//               }
//             }
//             if(a)
//             count++;
//         }
//         bool flag=1;
//         for(int j=0;j<v.size();j++){
//             if(visited[v[j]]==0){
//                 flag=0;
//                 break;
//             }
//         }
//         return flag==0?-1:count;
//     }
// };







class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int m=grid.size();int n=grid[0].size();
       int freshOranges=0;
       queue<pair<int,int>>q;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                freshOranges++;
            }
            if(grid[i][j]==2){
               q.push({i,j});
            }
        }
       }
       if(!freshOranges) return 0;
       int time=0;
       while(!q.empty()){
        int size=q.size();
        bool a=0;
        for(int i=0;i<size;i++){
        auto front=q.front();
        q.pop();
        vector<pair<int,int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        for (auto &each:dir){
            int newX=front.first+each.first;
            int newY=front.second+each.second;
            if(newX>=0 && newX<m && newY>=0&& newY<n && grid[newX][newY]==1){
                grid[newX][newY]=2;
                q.push({newX,newY});
                freshOranges--;
                a=1;
            }
        }
        }
        if(a)
        time++;
       }
       return (freshOranges==0)?time:-1;
    }
};