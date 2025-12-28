class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]<0) count++;
            }
        }
        return count;




        // int m=grid.size();
        // int n=grid[0].size();
        // int i=0;int j=n-1;
        // int ans=0;
        // while(i<m&&j>=0){
        //     if(grid[i][j]>=0){
        //         i++;
        //     }
        //     else{
        //       ans+=m-i;
        //       j--;
        //     }
        // }
        // return ans;
    }
};