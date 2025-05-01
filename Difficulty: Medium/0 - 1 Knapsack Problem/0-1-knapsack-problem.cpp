//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int w,vector<int>&val,vector<int>&wt,int i,vector<vector<int>>&dp){
        if(w==0||i>=wt.size())
        return 0;
        if(dp[w][i]!=-1)
        return dp[w][i];
        int l=0;
        if(wt[i]<=w)
        l=val[i]+solve(w-wt[i],val,wt,i+1,dp);
        int r=solve(w,val,wt,i+1,dp);
        return dp[w][i]=max(l,r);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int i=0;int n=wt.size();
        vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
        return solve(W,val,wt,i,dp);
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