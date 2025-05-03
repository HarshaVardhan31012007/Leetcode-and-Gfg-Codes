class Solution {
public:
    // bool issafe(vector<int>&c1,vector<int>&c2){
    //     if(c1[0]<=c2[0] && c1[1]<=c2[1] && c1[2]<=c2[2])
    //     return true;
    //     else
    //     return false;
    // }
    // int solve(vector<vector<int>>& cuboids,int prev,int curr,vector<vector<int>>&dp){
    //     if(curr>=cuboids.size()) return 0;
    //     if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];
    //     int l=0;
    //     if(prev==-1||issafe(cuboids[prev],cuboids[curr])){
    //         l=cuboids[curr][2]+solve(cuboids,curr,curr+1,dp);
    //     }
    //     int r=solve(cuboids,prev,curr+1,dp);
    //     return dp[curr][prev+1]=max(l,r);
    // }
    // int maxHeight(vector<vector<int>>& cuboids) {
    //     int n=cuboids.size();
    //     for(auto &cuboid:cuboids){
    //         sort(cuboid.begin(),cuboid.end());
    //     }
    //     sort(cuboids.begin(),cuboids.end());
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     return solve(cuboids,-1,0,dp);
    // }



    bool issafe(vector<int>&c1,vector<int>&c2){
        if(c1[0]<=c2[0] && c1[1]<=c2[1] && c1[2]<=c2[2])
        return true;
        else
        return false;
    }
    // int solve(vector<vector<int>>& cuboids,int n){
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //     for(int curr=n-1;curr>=0;curr--){
    //         for(int prev=curr-1;prev>=-1;prev--){
    //             int l=0;
    //             if(prev==-1||issafe(cuboids[prev],cuboids[curr]))
    //             l=cuboids[curr][2]+dp[curr+1][curr+1];
    //             int r=dp[curr+1][prev+1];
    //             dp[curr][prev+1]=max(l,r);
    //         }
    //     }
    //     return dp[0][0];
    // }

    int solve(vector<vector<int>>& cuboids,int n){
        vector<int>next(n+1,0);
        vector<int>cur(n+1,0);
        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){
                int l=0;
                if(prev==-1||issafe(cuboids[prev],cuboids[curr]))
                l=cuboids[curr][2]+next[curr+1];
                int r=next[prev+1];
                cur[prev+1]=max(l,r);
            }
            next=cur;
        }
        return next[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        for(auto &cuboid:cuboids){
            sort(cuboid.begin(),cuboid.end());
        }
        sort(cuboids.begin(),cuboids.end());
        return solve(cuboids,n);
    }
};