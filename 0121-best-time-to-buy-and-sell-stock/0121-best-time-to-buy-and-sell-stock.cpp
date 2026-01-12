class Solution {
public:
    int solve(vector<int>&prices,int i,int &mini){
        if(i>=prices.size()) return 0;
        int curr=prices[i]-mini;
        mini=min(mini,prices[i]);
        return max(curr,solve(prices,i+1,mini));
    }
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        return max(solve(prices,0,mini),0);
    }
};