class Solution {
  public:
   void solve(vector<vector<int>>&maze,int i,int j,vector<string>&ans,string temp,vector<vector<int>>&visited){
       if(i<0||j<0||i>=maze.size()||j>=maze.size()||maze[i][j]==0||visited[i][j]==1) return;
       if(i==maze.size()-1&&j==maze.size()-1) {
           ans.push_back(temp);
           return;
       }
       visited[i][j]=1;
       solve(maze,i-1,j,ans,temp+'U',visited);
       solve(maze,i+1,j,ans,temp+'D',visited);
       solve(maze,i,j-1,ans,temp+'L',visited);
       solve(maze,i,j+1,ans,temp+'R',visited);
       visited[i][j]=0;
   }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
       vector<string>ans;
       string  temp="";
       vector<vector<int>>visited(maze.size(),vector<int>(maze.size(),0));
       solve(maze,0,0,ans,temp,visited);
       sort(ans.begin(),ans.end());
       return ans;
    }
};