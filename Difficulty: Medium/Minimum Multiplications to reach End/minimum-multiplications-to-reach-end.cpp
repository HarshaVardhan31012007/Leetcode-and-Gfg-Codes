//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<int>q;
        const int mod=100000;
        vector<int>ans(100000,-1);
        q.push(start);
        ans[start]=0;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            if(front==end) return ans[end];
            for(int i=0;i<arr.size();i++){
                int n=(front*arr[i]) % mod;
                if(ans[n]==-1){
                q.push(n);
                ans[n]=ans[front]+1;
                }
            }
        }
        return -1;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends