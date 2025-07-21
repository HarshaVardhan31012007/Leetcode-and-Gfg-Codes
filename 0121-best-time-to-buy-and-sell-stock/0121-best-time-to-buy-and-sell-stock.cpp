class Solution {
public:
    void solve(vector<int>&prices,int i,int &bestbuy,int &maxprofit){
        if(i==prices.size()) return;
        if(prices[i]<bestbuy) bestbuy=prices[i];
        maxprofit=max(maxprofit,prices[i]-bestbuy);
        solve(prices,i+1,bestbuy,maxprofit);
    }
    int maxProfit(vector<int>& prices) {
        //method 1
        // int n=prices.size();
        // int maxi=0;//as min profit is zero in case of no transactions
        // for(int i=0;i<n;i++){
        //     int buyc=prices[i];
        //     for(int j=i+1;j<n;j++){
        //       int sellc=prices[j];
        //       maxi=max(maxi,sellc-buyc);
        //     }
        // }
        // return maxi;
       
        //method 2
        // int n=prices.size();
        // int maxi=INT_MIN;//if INT-MIN then if condition me equality hona chahihe//if 0 is there then equality no need
        // int bestbuy=prices[0];
        // for(int i=0;i<n;i++){
        //     if(prices[i]>=bestbuy){
        //         maxi=max(maxi,prices[i]-bestbuy);
        //     }
        //     bestbuy=min(bestbuy,prices[i]);
        // }
        // return maxi;

        
        //  int n=prices.size();
        // int maxi=0;//if INT-MIN then if condition me equality hona chahihe//if 0 is there then equality no need
        // int bestbuy=prices[0];
        // for(int i=1;i<n;i++){
        //     if(prices[i]>=bestbuy)//if you dont write also it works
        //     maxi=max(maxi,prices[i]-bestbuy);
        //     bestbuy=min(bestbuy,prices[i]);
        // }
        // return maxi;



        //method 3
        int bestbuy=INT_MAX;
        int maxprofit=INT_MIN;
        solve(prices,0,bestbuy,maxprofit);
        return maxprofit;
    }
};