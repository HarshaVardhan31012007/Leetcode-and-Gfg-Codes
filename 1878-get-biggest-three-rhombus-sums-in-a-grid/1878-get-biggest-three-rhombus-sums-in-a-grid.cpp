class Solution {
public:
    // class pair<int,int>{
    //     public:
    //     int x;
    //     int y;
    // };
    // int length1(vector<vector<int>>& grid,pair<int,int> a,pair<int,int> b){
    //     int sum=0;
    //     for(int i=a.x+1,j=a.y-1;i<b.x&&j>b.y;i++,j--){
    //           sum+=grid[i][j];
    //     }
    //     return sum;
    // }
    // int length2(vector<vector<int>>& grid,pair<int,int> a,pair<int,int> b){
    //     int sum=0;
    //     for(int i=a.x+1,j=a.y+1;i<b.x&&j<b.y;i++,j++){
    //           sum+=grid[i][j];
    //     }
    //     return sum;
    // }
    // vector<int>find(vector<vector<int>>& grid,int i,int j,int m,int n){
    //     int maxlength=min({i+1,j+1,m-i,n-j});
    //     vector<int>rhombus(maxlength,0);
    //     rhombus[0]=grid[i][j];
    //     for(int k=1;k<maxlength;k++){
    //          pair<int,int> l={i,j-k};
    //          pair<int,int> r={i,j+k};
    //          pair<int,int> u={i-k,j};
    //          pair<int,int> d={i+k,j};
    //          rhombus[k]+=length1(grid,u,l)+length2(grid,l,d)+length1(grid,r,d)+length2(grid,u,r)+grid[i][j-k]+grid[i][j+k]+grid[i-k][j]+grid[i+k][j];
    //     }
    //     return rhombus;
    // }
    // vector<int> getBiggestThree(vector<vector<int>>& grid) {
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     priority_queue<int,vector<int>,greater<>>pq;
    //     unordered_map<int,bool>mpp;
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             vector<int>v=find(grid,i,j,m,n);
    //             for(auto& sum:v){
    //                 if(!mpp.count(sum)){
    //                     pq.push(sum);
    //                     if(pq.size()>3)
    //                     pq.pop();
    //                     mpp[sum]=1;
    //                 }
    //             }
    //         }
    //     }
    //     vector<int>ans;
    //     while(!pq.empty()){
    //         ans.push_back(pq.top());
    //         pq.pop();
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    // }


    // class pair<int,int>{
    //     public:
    //     int x;
    //     int y;
    // };
    // int length1(vector<vector<int>>& grid,pair<int,int> a,pair<int,int> b){
    //     int sum=0;
    //     for(int i=a.x+1,j=a.y-1;i<b.x&&j>b.y;i++,j--){
    //           sum+=grid[i][j];
    //     }
    //     return sum;
    // }
    // int length2(vector<vector<int>>& grid,pair<int,int> a,pair<int,int> b){
    //     int sum=0;
    //     for(int i=a.x+1,j=a.y+1;i<b.x&&j<b.y;i++,j++){
    //           sum+=grid[i][j];
    //     }
    //     return sum;
    // }
    // void find(vector<vector<int>>& grid,int i,int j,int &m,int &n,unordered_map<int,bool>&mpp,priority_queue<int,vector<int>,greater<>>&pq){
    //     int maxlength=min({i+1,j+1,m-i,n-j});
    //     if(!mpp.count(grid[i][j])){
    //        pq.push(grid[i][j]);
    //        if(pq.size()>3)
    //        pq.pop();
    //        mpp[grid[i][j]]=1;
    //     }
    //     for(int k=1;k<maxlength;k++){
    //          pair<int,int> l={i,j-k};
    //          pair<int,int> r={i,j+k};
    //          pair<int,int> u={i-k,j};
    //          pair<int,int> d={i+k,j};
    //          int sum=length1(grid,u,l)+length2(grid,l,d)+length1(grid,r,d)+length2(grid,u,r)+grid[i][j-k]+grid[i][j+k]+grid[i-k][j]+grid[i+k][j];
    //             if(!mpp.count(sum)){
    //                 pq.push(sum);
    //                 if(pq.size()>3)
    //                 pq.pop();
    //                 mpp[sum]=1;
    //             }
    //     }
    // }
    // vector<int> getBiggestThree(vector<vector<int>>& grid) {
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     priority_queue<int,vector<int>,greater<>>pq;
    //     unordered_map<int,bool>mpp;
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             find(grid,i,j,m,n,mpp,pq);
    //         }
    //     }
    //     vector<int>ans;
    //     while(!pq.empty()){
    //         ans.push_back(pq.top());
    //         pq.pop();
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    // }




    //  class pair<int,int>{
    //     public:
    //     int x;
    //     int y;
    // };
    // int length1(vector<vector<int>>& grid,pair<int,int> a,pair<int,int> b){
    //     int sum=0;
    //     for(int i=a.x+1,j=a.y-1;i<b.x&&j>b.y;i++,j--){
    //           sum+=grid[i][j];
    //     }
    //     return sum;
    // }
    // int length2(vector<vector<int>>& grid,pair<int,int> a,pair<int,int> b){
    //     int sum=0;
    //     for(int i=a.x+1,j=a.y+1;i<b.x&&j<b.y;i++,j++){
    //           sum+=grid[i][j];
    //     }
    //     return sum;
    // }
    // void find(vector<vector<int>>& grid,int i,int j,int &m,int &n,priority_queue<int>&pq){
    //     int maxlength=min({i+1,j+1,m-i,n-j});
    //     pq.push(grid[i][j]);
    //     for(int k=1;k<maxlength;k++){
    //          pair<int,int> l={i,j-k};
    //          pair<int,int> r={i,j+k};
    //          pair<int,int> u={i-k,j};
    //          pair<int,int> d={i+k,j};
    //          int sum=length1(grid,u,l)+length2(grid,l,d)+length1(grid,r,d)+length2(grid,u,r)+grid[i][j-k]+grid[i][j+k]+grid[i-k][j]+grid[i+k][j];
    //         pq.push(sum);
    //     }
    // }
    // vector<int> getBiggestThree(vector<vector<int>>& grid) {
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     priority_queue<int>pq;
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             find(grid,i,j,m,n,pq);
    //         }
    //     }
    //     vector<int>ans;
    //     int count=3;
    //     while(!pq.empty()&&count){
    //         if(ans.empty()||ans.back()!=pq.top()){
    //             ans.push_back(pq.top());
    //             count--;
    //         }
    //         pq.pop();
    //     }
    //     return ans;
    // }



    
    int length1(vector<vector<int>>& grid,pair<int,int>&a,pair<int,int>&b){
        int sum=0;
        for(int k=1;k<(b.first-a.first);k++){
              sum+=grid[a.first+k][a.second-k];
        }
        return sum;
    }
    int length2(vector<vector<int>>& grid,pair<int,int>&a,pair<int,int>&b){
        int sum=0;
        for(int k=1;k<(b.first-a.first);k++){
              sum+=grid[a.first+k][a.second+k];
        }
        return sum;
    }
    bool checkBounds(pair<int,int>&p,int m,int n){
        return p.first>=0&&p.first<m&&p.second>=0&&p.second<n;
    }
    bool getAllVertices(vector<pair<int,int>>&v,int i,int j,int &m,int &n,int k){
         v[0]={i,j-k};
         v[1]={i,j+k};
         v[2]={i-k,j};
         v[3]={i+k,j};
         if(checkBounds(v[0],m,n)&&checkBounds(v[1],m,n)&&checkBounds(v[2],m,n)&&checkBounds(v[3],m,n))
         return true;
         return false;
    }
    void find(vector<vector<int>>& grid,int i,int j,int &m,int &n,priority_queue<int>&pq){
        pq.push(grid[i][j]);
        vector<pair<int,int>>v(4);
        int k=1;
        while(getAllVertices(v,i,j,m,n,k)){
             pair<int,int>&l=v[0];
             pair<int,int>&r=v[1];
             pair<int,int>&u=v[2];
             pair<int,int>&d=v[3];
             int sum=length1(grid,u,l)+length2(grid,l,d)+length1(grid,r,d)+length2(grid,u,r)+grid[i][j-k]+grid[i][j+k]+grid[i-k][j]+grid[i+k][j];
             pq.push(sum);
             k+=1;
        }
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<int>pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                find(grid,i,j,m,n,pq);
            }
        }
        vector<int>ans;
        int count=3;
        while(!pq.empty()&&count){
            if(ans.empty()||ans.back()!=pq.top()){
                ans.push_back(pq.top());
                count--;
            }
            pq.pop();
        }
        return ans;
    }
};