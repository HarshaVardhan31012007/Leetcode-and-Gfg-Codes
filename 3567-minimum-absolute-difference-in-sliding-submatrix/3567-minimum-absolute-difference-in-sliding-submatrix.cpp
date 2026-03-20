class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>ans1(m-k+1,vector<int>(n-k+1,0));
        for(int i=0;i<=m-k;i++){
            for(int j=0;j<=n-k;j++){
                long long int ans=1e11;
                set<int>temp;
                for(int p=i;p<=i+k-1;p++){
                    for(int q=j;q<=j+k-1;q++){
                        temp.insert(grid[p][q]);
                    }
                }
                int prev=1e6;
                for(auto &each:temp){
                    if(prev!=1e6){
                       ans=min(ans,1LL*(abs(prev-each)));
                    }
                    prev=each;
                }
                ans1[i][j]=(ans==1e11?0:ans);
            }
        }
        return ans1;
    }
};