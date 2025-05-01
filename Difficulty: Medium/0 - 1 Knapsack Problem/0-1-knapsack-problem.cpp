//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
       
    //int solve(int w,vector<int>&val,vector<int>&wt,int i){
        // if(i>=wt.size())
        // return 0;
        // if(i==wt.size()-1){
        //     if(wt[i]<=w)
        //     return val[i];
        //     else
        //     return 0;
        // }
        
        //if(w==0||i>=wt.size())
        // return 0;
    //     int l=0;
    //     if(wt[i]<=w)
    //     l=val[i]+solve(w-wt[i],val,wt,i+1);
    //     int r=solve(w,val,wt,i+1);
    //     return max(l,r);
    // }
    // int knapsack(int W, vector<int> &val, vector<int> &wt) {
    //     int i=0;
    //     return solve(W,val,wt,i);
    // }  
    
    
    
    // int solve(int w,vector<int>&val,vector<int>&wt,int i,vector<vector<int>>&dp){
    //     if(w==0||i>=wt.size())
    //     return 0;
    //     if(dp[w][i]!=-1)
    //     return dp[w][i];
    //     int l=0;
    //     if(wt[i]<=w)
    //     l=val[i]+solve(w-wt[i],val,wt,i+1,dp);
    //     int r=solve(w,val,wt,i+1,dp);
    //     return dp[w][i]=max(l,r);
    // }
    // int knapsack(int W, vector<int> &val, vector<int> &wt) {
    //     int i=0;int n=wt.size();
    //     vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
    //     return solve(W,val,wt,i,dp);
    // }
    
    
    
    // int solve(int w,vector<int>&val,vector<int>&wt,int n){
    //   vector<vector<int>>dp(w+1,vector<int>(n+1,-1));
    //   for(int i=0;i<n+1;i++)
    //   dp[0][i]=0;
    //     for(int i=0;i<w+1;i++)
    //     dp[i][n]=0;
        
    //   for(int i=1;i<=w;i++){
    //       for(int j=n-1;j>=0;j--){
    //     int l=0;
    //     if(wt[j]<=i)
    //     l=val[j]+dp[i-wt[j]][j+1];
    //     int r=dp[i][j+1];
    //     dp[i][j]=max(l,r);
    //       }
    //   }
    //   return dp[w][0];
    // }
    // int knapsack(int W, vector<int> &val, vector<int> &wt) {
    //     int n=wt.size();
    //     return solve(W,val,wt,n);
    // }
    
    
    
     
     //  MAIN MAIN Solution indices can from start to end .but for convience we take end tos tart
     
      int solve(int w,vector<int>&val,vector<int>&wt,vector<vector<int>>&dp,int i){
          if(i==0){
              if(wt[i]<=w)
              return val[i];
              else
              return 0;
          }
          if(dp[w][i]!=-1)
          return dp[w][i];
          int l=0;
          if(wt[i]<=w)
          l=val[i]+solve(w-wt[i],val,wt,dp,i-1);
          int r=solve(w,val,wt,dp,i-1);
          return dp[w][i]=max(l,r);
      }
      int knapsack(int W,vector<int>&val,vector<int>&wt){
          int n=wt.size();
          vector<vector<int>>dp(W+1,vector<int>(n,-1));
          int i=n-1;
          return solve(W,val,wt,dp,i);
      }
};


//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends