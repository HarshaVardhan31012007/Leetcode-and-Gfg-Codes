class Solution {
public:
    // vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     vector<vector<int>>ans(m,vector<int>(n,0));
    //     for(int i=0;i<m;i++){
    //         for(int j=0;j<n;j++){
    //             int newindex=(i*n+j+k)%(m*n);
    //             int r=newindex/n;
    //             int c=newindex%n;
    //             ans[r][c]=grid[i][j];
    //         }
    //     }
    //     return ans;
    // }


    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>temp;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp.push_back(grid[i][j]);
            }
        }
        k=k%(m*n);
        reverse(temp.begin(),temp.end());
        reverse(temp.begin(),temp.begin()+k);
        reverse(temp.begin()+k,temp.end());
        int idx=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                grid[i][j]=temp[idx++];
            }
        }
        return grid;
    }
};