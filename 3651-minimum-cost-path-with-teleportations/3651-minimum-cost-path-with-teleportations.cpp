// class Solution {
// public:
//     // int solve(vector<vector<int>>&grid,int i,int j,int m,int n,int k,vector<vector<vector<int>>>&dp){
//     //     if(i==m-1&&j==n-1) return 0;
//     //     if(dp[i][j][k]!=-1) return dp[i][j][k];
//     //     int ans=INT_MAX;
//     //     if(j+1<n)
//     //     ans=min(ans,grid[i][j+1]+solve(grid,i,j+1,m,n,k,dp));
//     //     if(i+1<m)
//     //     ans=min(ans,grid[i+1][j]+solve(grid,i+1,j,m,n,k,dp));
//     //     for(int p=0;p<m;p++){
//     //         for(int q=0;q<n;q++){
//     //             if(k>0&&grid[p][q]<=grid[i][j]){
//     //                 ans=min(ans,solve(grid,p,q,m,n,k-1,dp));
//     //             }
//     //         }
//     //     }
//     //     return dp[i][j][k]=ans;
//     // }
//     // int minCost(vector<vector<int>>& grid, int k) {
//     //     int m=grid.size();int n=grid[0].size();
//     //     if(k>0&&grid[0][0]>=grid[m-1][n-1]) return 0;
//     //     vector<vector<vector<int>>>dp(m+2,vector<vector<int>>(n+2,vector<int>(k+2,-1)));
//     //     return solve(grid,0,0,m,n,k,dp);
//     // }



//     //  int solve(vector<vector<int>>&grid,int i,int j,int m,int n,int k,vector<vector<vector<int>>>&dp){
//     //     if(i==m-1&&j==n-1) return 0;
//     //     if(dp[i][j][k]!=-1) return dp[i][j][k];
//     //     int ans=INT_MAX;
//     //     if(j+1<n)
//     //     ans=min(ans,grid[i][j+1]+solve(grid,i,j+1,m,n,k,dp));
//     //     if(i+1<m)
//     //     ans=min(ans,grid[i+1][j]+solve(grid,i+1,j,m,n,k,dp));
//     //     for(int p=0;p<m;p++){
//     //         for(int q=0;q<n;q++){
//     //             if(k>0&&grid[p][q]<=grid[i][j]){
//     //                 ans=min(ans,solve(grid,p,q,m,n,k-1,dp));
//     //             }
//     //         }
//     //     }
//     //     return dp[i][j][k]=ans;
//     // }
//     // int minCost(vector<vector<int>>& grid, int k) {
//     //     int m=grid.size();int n=grid[0].size();
//     //     vector<vector<vector<int>>>dp(k+1,vector<vector<int>>(m+1,vector<int>(n+1,INT_MAX)));
//     //     for(int j=0;j<k;j++){
//     //         dp[m-1][n-1]=0;
//     //     }
//     //     int ans=INT_MAX;int prev=INT_MAX;
//     //     for(int p=0;p<k;p++){
//     //         int curr=1e9;
//     //         for(int i=m-1;i>=0;i--){
//     //             for(int j=n-1;j>=0;j--){
//     //                 if(i+1<m)
//     //                 curr=min(curr,grid[i+1][j]+dp[i+1][j]);
//     //                 if(j+1<n)
//     //                 curr=min(curr,grid[i][j+1]+dp[i][j+1]);
//     //                 curr=min(curr,prev)
//     //             }
//     //         }
//     //     }
//     // }
// };




// class Solution {
// public:
//     typedef pair<int,pair<int,pair<int,int>>>PP;
//     int minCost(vector<vector<int>>& grid, int k) {
//     priority_queue<PP,vector<PP>,greater<>>pq;
//         int m=grid.size();int n=grid[0].size();
//         vector<vector<vector<int>>>cost(m,vector<vector<int>>(n,vector<int>(k+1,INT_MAX)));
//         cost[0][0][k]=0;
//         pq.push({0,{k,{0,0}}});
//         while(!pq.empty()){
//             auto top=pq.top();
//             pq.pop();
//             int x=top.second.second.first;
//             int y=top.second.second.second;
//             int dist=top.first;
//             int k1=top.second.first;
//             if(x==m-1&&y==n-1) return dist;
//             if(x+1<m&&dist+grid[x+1][y]<cost[x+1][y][k1]){
//                 cost[x+1][y][k1]=dist+grid[x+1][y];
//                 pq.push({cost[x+1][y][k1],{k1,{x+1,y}}});
//             }
//             if(y+1<n&&dist+grid[x][y+1]<cost[x][y+1][k1]){
//                 cost[x][y+1][k1]=dist+grid[x][y+1];
//                 pq.push({cost[x][y+1][k1],{k1,{x,y+1}}});
//             }
//             for(int i=0;i<m;i++){
//                 for(int j=0;j<n;j++){
//                     if(k1>0&&grid[i][j]<=grid[x][y]&&dist<cost[i][j][k1-1]){
//                         cost[i][j][k1-1]=dist;
//                         pq.push({dist,{k1-1,{i,j}}});
//                     }
//                 }
//             }
//         }
//        return -1;
//     }
// };




class Solution {
public:
    typedef pair<int,pair<int,pair<int,int>>>PP;
    int minCost(vector<vector<int>>& grid, int k) {
    priority_queue<PP,vector<PP>,greater<>>pq;
    vector<int>index(k+1,0);
        int m=grid.size();int n=grid[0].size();
        vector<vector<int>>cells;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cells.push_back({grid[i][j],i,j});
            }
        }
        sort(cells.begin(),cells.end());
        vector<vector<vector<int>>>cost(m,vector<vector<int>>(n,vector<int>(k+1,INT_MAX)));
        cost[0][0][k]=0;
        pq.push({0,{k,{0,0}}});
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int x=top.second.second.first;
            int y=top.second.second.second;
            int dist=top.first;
            int k1=top.second.first;
            if(x==m-1&&y==n-1) return dist;
            if(x+1<m&&dist+grid[x+1][y]<cost[x+1][y][k1]){
                cost[x+1][y][k1]=dist+grid[x+1][y];
                pq.push({cost[x+1][y][k1],{k1,{x+1,y}}});
            }
            if(y+1<n&&dist+grid[x][y+1]<cost[x][y+1][k1]){
                cost[x][y+1][k1]=dist+grid[x][y+1];
                pq.push({cost[x][y+1][k1],{k1,{x,y+1}}});
            }
            for(int idx=index[k1];idx<cells.size();idx++){
                vector<int>&each=cells[idx];
                if(each[0]>grid[x][y]) break;
                if(k1>0&&dist<cost[each[1]][each[2]][k1-1]){
                    cost[each[1]][each[2]][k1-1]=dist;
                    pq.push({dist,{k1-1,{each[1],each[2]}}});
                }
                index[k1]++;
            }
        }
       return -1;
    }
};