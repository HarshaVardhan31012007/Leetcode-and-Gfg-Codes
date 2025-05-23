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


    //  int solve(int i,vector<int>& days, vector<int>& costs,vector<int>&dp){
    //     if(i==days.size())
    //     return 0;
    //     if(dp[i]!=-1)
    //     return dp[i];
    //     int a=costs[0]+solve(i+1,days,costs,dp);
    //     int passday=days[i]+7-1;
    //     int j=i;
    //     while(j<days.size()&&days[j]<=passday){
    //         j++;
    //     }
    //     int b=costs[1]+solve(j,days,costs,dp);
    //     passday=days[i]+30-1;
    //     j=i;
    //     while(j<days.size()&&days[j]<=passday){
    //         j++;
    //     }
    //     int c=costs[2]+solve(j,days,costs,dp);
    //     return dp[i]=min(a,min(b,c));
    // }
    // int mincostTickets(vector<int>& days, vector<int>& costs) {
    //     vector<int>dp(days.size()+1,-1);
    //     return solve(0,days,costs,dp);
    // }


    // int solve(vector<int>& days, vector<int>& costs){
    //      vector<int>dp(days.size()+1,-1);
    //      dp[days.size()]=0;
    //      for(int i=days.size()-1;i>=0;i--){
    //     int a=costs[0]+dp[i+1];
    //     int passday=days[i]+7-1;
    //     int j=i;
    //     while(j<days.size()&&days[j]<=passday){
    //         j++;
    //     }
    //     int b=costs[1]+dp[j];
    //     passday=days[i]+30-1;
    //     j=i;
    //     while(j<days.size()&&days[j]<=passday){
    //         j++;
    //     }
    //     int c=costs[2]+dp[j];
    //     dp[i]=min(a,min(b,c));
    //      }
    //      return dp[0];
    // }
    // int mincostTickets(vector<int>& days, vector<int>& costs) {
    //     return solve(days,costs);
    // }


    // int solve(vector<int>& days, vector<int>& costs){
    //      vector<int>dp(days.size()+1,-1);
    //      dp[days.size()]=0;
    //      for(int i=days.size()-1;i>=0;i--){
    //     int a=costs[0]+dp[i+1];
    //     int j;
    //     for(j=i;j<days.size()&&days[j]<days[i]+7;j++);
    //     int b=costs[1]+dp[j];
    //     for(j=i;j<days.size()&&days[j]<days[i]+30;j++);
    //     int c=costs[2]+dp[j];
    //     dp[i]=min(a,min(b,c));
    //      }
    //      return dp[0];
    // }
    // int mincostTickets(vector<int>& days, vector<int>& costs) {
    //     return solve(days,costs);
    // }

     int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans=0;
        queue<pair<int,int>>month;
        queue<pair<int,int>>week;
        for(int &day:days){
            while(!month.empty()&&day>=month.front().first+30)
            month.pop();
            while(!week.empty()&&day>=week.front().first+7)
            week.pop();
            month.push(make_pair(day,ans+costs[2]));
            week.push(make_pair(day,ans+costs[1]));
            ans=min(ans+costs[0],min(week.front().second,month.front().second));
        }
        return ans;
     }
};