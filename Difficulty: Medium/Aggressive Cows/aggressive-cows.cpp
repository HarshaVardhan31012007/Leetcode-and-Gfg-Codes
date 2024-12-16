//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     bool possible(vector<int>&arr,int n,int k,int mid){
        int lastpos=arr[0];
        int c=1;
        for(int i=0;i<n;i++){
            if(arr[i]-lastpos>=mid){
                c++;
                if(c==k)
                return true;
                lastpos=arr[i];
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int s=0;
        int e=arr[n-1]-arr[0];
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(arr,n,k,mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends