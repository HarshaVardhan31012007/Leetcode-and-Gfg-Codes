class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int m=grid.size();int n=grid[0].size();
        vector<int>v;
        for(int i=0;i<m;i++){
            int c=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==0) c++;
                else break;
            }
            v.push_back(c);
        }
        int ans=0;
        for(int i=0;i<m;i++){
           int need=n-i-1;
           int j=i;
           while(j<n&&v[j]<need){
               j++;
           }
           if(j==n) return -1;
           ans+=j-i;
           while(j>i){
              swap(v[j],v[j-1]);
              j--;
           }
        }
        return ans;
    }
};