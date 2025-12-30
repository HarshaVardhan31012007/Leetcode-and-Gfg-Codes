class Solution {
public:
    // bool check(vector<vector<int>>&grid,int i,int j,int m,int n){
    //    if(i+2>=m||j+2>=n){
    //        return false;
    //    }
    //    vector<int>v(10,0);
    //    for(int x=0;x<=2;x++){
    //      for(int y=0;y<=2;y++){
    //          int idx=grid[i+x][j+y];
    //          if(idx>=1&&idx<=9&&!v[idx]){
    //              v[idx]=1;
    //          }
    //          else
    //           return false;
    //      }
    //    }
    //    int sum=grid[i][j]+grid[i][j+1]+grid[i][j+2];
    //    int curr=grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2];
    //     if(curr!=sum) return false;
    //     curr=grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
    //     if(curr!=sum) return false;
    //     curr=grid[i][j]+grid[i+1][j]+grid[i+2][j];
    //     if(curr!=sum) return false;
    //     curr=grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1];
    //     if(curr!=sum) return false;
    //     curr=grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2];
    //     if(curr!=sum) return false;
    //     curr=grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2];
    //     if(curr!=sum) return false;
    //     curr=grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j];
    //     if(curr!=sum) return false;
    //     return true;
    // }
    // int numMagicSquaresInside(vector<vector<int>>& grid) {
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     int ans=0;
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             if(check(grid,i,j,m,n)){
    //                 ans++;
    //             }
    //         }
    //     }
    //     return ans;
    // }




    bool check(vector<vector<int>>&grid,int i,int j,int m,int n){
       vector<int>v(10,0);
       for(int x=0;x<=2;x++){
         for(int y=0;y<=2;y++){
             int idx=grid[i+x][j+y];
             if(idx>=1&&idx<=9&&!v[idx]){
                 v[idx]=1;
             }
             else
              return false;
         }
       }
        int sum=grid[i][j]+grid[i][j+1]+grid[i][j+2];
        for(int k=0;k<3;k++){
            if(grid[i+k][j]+grid[i+k][j+1]+grid[i+k][j+2]!=sum) return false;
            if(grid[i][j+k]+grid[i+1][j+k]+grid[i+2][j+k]!=sum) return false;
        }
        if(grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]!=sum) return false;
        if(grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]!=sum) return false;
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<=m-3;i++){
            for(int j=0;j<=n-3;j++){
                if(check(grid,i,j,m,n)){
                    ans++;
                }
            }
        }
        return ans;
    }
};