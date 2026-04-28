class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        int m=grid.size();
        int n=grid[0].size();
        if(m*n==1) return 0;
        int rem=grid[0][0]%x;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]%x!=rem) return -1;
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        n=arr.size();
        int m1=arr[n/2-1];
        int m2=arr[n/2];
        int ans1=0;
        int ans2=0;
        for(int i=0;i<n;i++){
           ans1+=abs(arr[i]-m1)/x;
           ans2+=abs(arr[i]-m2)/x;
        }
        return min(ans1,ans2);
    }
};