class Solution {
public:
    // int solve(int day,int i,vector<int>& days, vector<int>& costs,vector<vector<int>>&dp){
    //     //Base case
    //     if(i==days.size()||day>=366)
    //     return 0;
    //     if(dp[i][day]!=-1)
    //     return dp[i][day];
    //     //One case
    //     if(day<=days[i]){
    //     int a=costs[0]+solve(days[i]+1,i+1,days,costs,dp);
    //     int b=costs[1]+solve(days[i]+7,i+1,days,costs,dp);
    //     int c=costs[2]+solve(days[i]+30,i+1,days,costs,dp);
    //     return min(a,min(b,c));
    //     }
    //     return dp[i][day]=solve(day,i+1,days,costs,dp);
    // }
    // int mincostTickets(vector<int>& days, vector<int>& costs) {
    //     vector<vector<int>>dp(days.size()+1,vector<int>(366,-1));
    //     return solve(days[0],0,days,costs,dp);
    // }


     int solve(int i,vector<int>& days, vector<int>& costs,vector<int>&dp){
        if(i==days.size())
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int a=costs[0]+solve(i+1,days,costs,dp);
        int passday=days[i]+7-1;
        int j=i;
        while(j<days.size()&&days[j]<=passday){
            j++;
        }
        int b=costs[1]+solve(j,days,costs,dp);
        passday=days[i]+30-1;
        j=i;
        while(j<days.size()&&days[j]<=passday){
            j++;
        }
        int c=costs[2]+solve(j,days,costs,dp);
        return dp[i]=min(a,min(b,c));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size()+1,-1);
        return solve(0,days,costs,dp);
    }
};