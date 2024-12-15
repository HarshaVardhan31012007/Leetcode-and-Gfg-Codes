//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
   bool possible(vector<int>&arr,int n,int k,long long int sol){//sol means solution
        long long int pageSum=0;
        int c=1;
        for(int i=0;i<n;i++){
            if(arr[i]>sol)
            return false;
            if(pageSum+arr[i]>sol){
                c++;
                if(c>k)
                return false;
                pageSum=arr[i];
            }
            else{
                pageSum+=arr[i];
            }
        }
        return true;
    }
    
    int minTime(vector<int>& arr, int k) {
        int n=arr.size();
       // if(n<k) return -1;
        long long int s=0;
        long long int e=accumulate(arr.begin(),arr.end(),0);
        long long int ans=-1;
        while(s<=e){
            long long int mid=s+(e-s)/2;
            if(possible(arr,n,k,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends