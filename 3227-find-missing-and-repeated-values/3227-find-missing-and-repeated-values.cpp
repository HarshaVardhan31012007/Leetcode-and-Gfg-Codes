class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    //    unordered_map<int,int>mpp;
    //    vector<int>ans(2);
    //    int n=grid.size();
    //    for(int i=0;i<n*n;i++)
    //    mpp[i+1]=1;
    //    for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(mpp[grid[i][j]]==0)
    //          ans[0]=grid[i][j];
    //          mpp[grid[i][j]]=0;
    //     }
    //    }
    //    for(auto &each:mpp){
    //     if(each.second==1)
    //     ans[1]=each.first;
    //    }
    //    return ans;



    //    vector<int>ans(2);
    //    int n=grid.size();
    //    for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //        int row=(abs(grid[i][j])-1)/n;
    //        int col=(abs(grid[i][j])-1)%n;
    //        if(grid[row][col]<0)
    //        ans[0]=n*row+col+1;
    //        else
    //        grid[row][col]*=-1;
    //     }
    //    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         if(grid[i][j]>0){
    //         ans[1]=n*i+j+1;
    //         break;
    //         }
    //     }
    // }
    //     return ans;



       vector<int>ans(2);
       unordered_map<int,int>mpp;
       int n=grid.size();
       int sum=((n*n)*((n*n)+1))/2;
       int asum=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          asum+=grid[i][j];
          if(mpp.find(grid[i][j])!=mpp.end()){
            ans[0]=grid[i][j];
          }
          mpp[grid[i][j]]=1;
        }
       }
       ans[1]=sum-asum+ans[0];
       return ans;
    }
};