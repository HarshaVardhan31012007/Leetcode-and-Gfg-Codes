class Solution {
public:
    class Point{
        public:
        int x;
        int y;
    };
    int length1(vector<vector<int>>& grid,Point a,Point b){
        int sum=0;
        for(int i=a.x+1,j=a.y-1;i<b.x&&j>b.y;i++,j--){
              sum+=grid[i][j];
        }
        return sum;
    }
    int length2(vector<vector<int>>& grid,Point a,Point b){
        int sum=0;
        for(int i=a.x+1,j=a.y+1;i<b.x&&j<b.y;i++,j++){
              sum+=grid[i][j];
        }
        return sum;
    }
    vector<int>find(vector<vector<int>>& grid,int i,int j,int m,int n){
        int maxlength=min({i+1,j+1,m-i,n-j});
        vector<int>rhombus(maxlength,0);
        rhombus[0]=grid[i][j];
        for(int k=1;k<maxlength;k++){
             Point l={i,j-k};
             Point r={i,j+k};
             Point u={i-k,j};
             Point d={i+k,j};
             rhombus[k]+=length1(grid,u,l)+length2(grid,l,d)+length1(grid,r,d)+length2(grid,u,r)+grid[i][j-k]+grid[i][j+k]+grid[i-k][j]+grid[i+k][j];
        }
        return rhombus;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<int,vector<int>,greater<>>pq;
        unordered_map<int,bool>mpp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<int>v=find(grid,i,j,m,n);
                for(auto& sum:v){
                    if(!mpp.count(sum)){
                        pq.push(sum);
                        if(pq.size()>3)
                        pq.pop();
                        mpp[sum]=1;
                    }
                }
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};