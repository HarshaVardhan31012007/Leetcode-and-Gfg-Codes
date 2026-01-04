class Solution {
public:
    const int mod=1e9+7;
    int numberOfRoutes(vector<string>& grid, int d) {
        int n=grid.size();int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dp[n-1][i]=((grid[n-1][i]=='.')?1:0);
        }
        vector<int>pref(m+1,0);
        for(int i=0;i<m;i++){
            pref[i+1]=(pref[i]+dp[n-1][i])%mod;
        }
        for(int i=0;i<m;i++){
            if(grid[n-1][i]=='#') continue;
            int L=max(0,i-d);int R=min(m-1,i+d);
            long long fsame=(pref[R+1]-pref[L]-dp[n-1][i])%mod;
            dp[n-1][i]=(dp[n-1][i]+fsame)%mod;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                pref[j+1]=(pref[j]+dp[i+1][j])%mod;
            }
            int w=sqrt(1LL*d*d-1);//stored in int so rounded off automatically
            for(int j=0;j<m;j++){
                if(grid[i][j]=='#') continue;
                int L=max(0,j-w);int R=min(m-1,j+w);
                dp[i][j]=(pref[R+1]-pref[L]+mod)%mod;
            }
            for(int j=0;j<m;j++){
                pref[j+1]=(pref[j]+dp[i][j])%mod;
            }
            for(int j=0;j<m;j++){
                if(grid[i][j]=='#') continue;
                int L=max(0,j-d);int R=min(m-1,j+d);
                long long fsame=(pref[R+1]-pref[L]-dp[i][j]+mod)%mod;
                dp[i][j]=(dp[i][j]+fsame)%mod;
            }
        }
        long long res=0;
        for(int i=0;i<m;i++){
            res=(res+dp[0][i])%mod;
        }
        return res;
    }
};