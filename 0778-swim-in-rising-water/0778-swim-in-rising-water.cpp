class Solution {
public:
    bool possible(vector<vector<int>>&grid,int i,int j,int s,int e,int mid){
        queue<pair<int,int>>q;
        vector<vector<int>>visited(s+1,vector<int>(e+1,0));
        if(grid[0][0]<=mid){
            q.push({0,0});
            visited[0][0]=1;
        }
        while(!q.empty()){
            auto front=q.front();
            int x=front.first;
            int y=front.second;
            q.pop();
            if(x==s&&y==e) return true;
            int dx[]={-1,1,0,0};
            int dy[]={0,0,-1,1};
            for(int k=0;k<4;k++){
                int p=x+dx[k];
                int q1=y+dy[k];
                if(p<0||q1<0||p>=grid.size()||q1>=grid[0].size()||grid[p][q1]>mid||visited[p][q1]) continue;
                visited[p][q1]=1;
                q.push({p,q1});
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int s=grid[0][0];
        int e=INT_MIN;
        for(int i=0;i<m;i++)
        e=max(e,*max_element(grid[i].begin(),grid[i].end()));
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(grid,0,0,m-1,n-1,mid)){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
};