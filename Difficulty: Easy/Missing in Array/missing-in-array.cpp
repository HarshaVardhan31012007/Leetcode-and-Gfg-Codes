//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int missingNumber(int n, vector<int>& arr) {
           sort(arr.begin(),arr.end());
           int s=0;
           int e=n-2;
           int ansIndex=-1;
           while(s<=e){
           int mid=s+(e-s)/2;
           int diff=arr[mid]-mid;
           if(diff==1){
               s=mid+1;
               if(s>n-2)
               ansIndex=n;
           }
           else if(diff>1){
               ansIndex=mid+1;
               e=mid-1;
           }
           mid=s+(e-s)/2;
           }
           return ansIndex;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.missingNumber(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends