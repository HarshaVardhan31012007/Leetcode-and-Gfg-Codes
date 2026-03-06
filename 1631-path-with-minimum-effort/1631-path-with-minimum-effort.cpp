class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>q;
        int m=heights.size();int n=heights[0].size();
        vector<vector<int>>effort(m,vector<int>(n,INT_MAX));
        effort[0][0]=0;
        q.push({0,{0,0}});
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty()){
           auto top=q.top();
           int e=q.top().first;
           int r=q.top().second.first;
           int c=q.top().second.second;
           q.pop();
           if(r==m-1&&c==n-1) return e;
           if(e>effort[r][c]) continue;
           for(int i=0;i<4;i++){
              int x=r+dx[i];
              int y=c+dy[i];
              if(x<0||y<0||x>=m||y>=n) continue;
              int currdiff=abs(heights[r][c]-heights[x][y]);
              if(max(e,currdiff)<effort[x][y]){
                 effort[x][y]=max(e,currdiff);
                 q.push({effort[x][y],{x,y}});
              }
           }
        }
        return -1;
    }
};