class Solution {
public:
    // int solve(int i,vector<int>&days,vector<int>&costs,vector<int>&dp){
    //       if(i>=days.size()) return 0;
    //       if(dp[i]!=-1) return dp[i];
    //       int one=costs[0]+solve(i+1,days,costs,dp);
    //       int j=i;
    //       while(j<days.size()&&days[j]<days[i]+7)
    //       j++;
    //       int seven=costs[1]+solve(j,days,costs,dp);
    //       j=i;
    //       while(j<days.size()&&days[j]<days[i]+30)
    //       j++;
    //       int thirty=costs[2]+solve(j,days,costs,dp);
    //       return dp[i]=min(one,min(seven,thirty));
    // }
    // int mincostTickets(vector<int>& days, vector<int>& costs) {
    //     vector<int>dp(days.size()+1,-1);
    //     return solve(0,days,costs,dp);
    // }



    // int mincostTickets(vector<int>& days, vector<int>& costs) {
    //     vector<int>dp(days.size()+1,0);
    //     for(int i=days.size()-1;i>=0;i--){
    //         int one=costs[0]+dp[i+1];
    //         int j=lower_bound(days.begin()+i+1,days.end(),days[i]+7)-days.begin();
    //         int seven=costs[1]+dp[j];
    //         j=lower_bound(days.begin()+i+1,days.end(),days[i]+30)-days.begin();
    //         int thirty=costs[2]+dp[j];
    //         dp[i]=min(one,min(seven,thirty));
    //     }
    //     return dp[0];
    // }



    int mincostTickets(vector<int>& days, vector<int>& costs) {
        queue<pair<int,int>>week;
        queue<pair<int,int>>month;
        int ans=0;
        for(auto &day:days){
            while(!week.empty()&&day>=week.front().first+7)
            week.pop();
            while(!month.empty()&&day>=month.front().first+30)
            month.pop();
            week.push(make_pair(day,ans+costs[1]));
            month.push(make_pair(day,ans+costs[2]));
            ans=min(ans+costs[0],min(week.front().second,month.front().second));
        }
        return ans;
    }
};