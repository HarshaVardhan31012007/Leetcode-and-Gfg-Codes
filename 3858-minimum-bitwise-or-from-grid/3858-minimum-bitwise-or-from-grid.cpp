class Solution {
public:
    // unordered_map<int,unordered_set<int>>dp;
    // void solve(int i,vector<vector<int>>& grid,int m,int n,int val,int &mini){
    //     if(val>=mini) return;
    //     if(i>=m){
    //         mini=min(mini,val);
    //         return;
    //     }
    //     if(dp.count(i)){
    //         if(dp[i].count(val)) return;
    //     }
    //     for(int j=0;j<n;j++){
    //         solve(i+1,grid,m,n,val|grid[i][j],mini);
    //     }
    //     dp[i].insert(val);
    // }
    // int minimumOR(vector<vector<int>>& grid) {
    //     int m=grid.size();int n=grid[0].size();
    //     int mini=INT_MAX;
    //     solve(0,grid,m,n,0,mini);
    //     return mini;
    // }



    
    int minimumOR(vector<vector<int>>& grid) {
        int m=grid.size();int n=grid[0].size();
        int ans=0;
        int forbidden=0;
        for(int k=31;k>=0;k--){
            bool possible=true;
            int tempforbidden=forbidden|(1<<k);
            for(int i=0;i<m;i++){
                bool found=false;
                for(int j=0;j<n;j++){
                     if((grid[i][j]&tempforbidden)==0){
                        found=true;
                        break;
                     }
                }
                if(!found){
                    possible=false;
                    break;
                }
            }
            if(!possible){
               ans=(ans|(1<<k));
            }
            else{
                forbidden=tempforbidden;
            }
        }
        return ans;
    }
};