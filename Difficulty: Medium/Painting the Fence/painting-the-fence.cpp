//{ Driver Code Starts
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int n,int k,vector<int>&dp){
        if(n==1)
        return k;
        if(n==2)
        return k*k;
        if(dp[n-1]!=-1)
        return dp[n-1];
        return dp[n-1]=(k-1)*(solve(n-1,k,dp)+solve(n-2,k,dp));
    }
    int countWays(int n, int k) {
        vector<int>dp(n,-1);
        return solve(n,k,dp);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.countWays(n, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends