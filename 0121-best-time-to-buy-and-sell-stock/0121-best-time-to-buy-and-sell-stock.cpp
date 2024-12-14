class Solution {
public:
    // int solve(vector<int>& prices,int buyc,int sellc,int i){
    //     if(i==prices.size()){

    //     }
    //     buyc=prices[i];
    //     int maxi=INT_MIN;
    //     for(int j=i+1;j<prices.size();j++){
    //       maxi=max(maxi,prices[j]);
    //     }

    // }
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
        int n=prices.size();
        int maxi=INT_MIN;
        int bestbuy=prices[0];
        for(int i=0;i<n;i++){
            if(prices[i]>=bestbuy){
                maxi=max(maxi,prices[i]-bestbuy);
            }
            bestbuy=min(bestbuy,prices[i]);
        }
        return maxi;

        //method 3
    }
};