//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
   bool possible(vector<int>&arr,int n,int k,int sol){//sol means solution
        int timeSum=0;
        int c=1;
        for(int i=0;i<n;i++){
            if(arr[i]>sol)
            return false;
            if(timeSum+arr[i]>sol){
                c++;
                if(c>k)
                return false;
                timeSum=arr[i];
            }
            else{
                timeSum+=arr[i];
            }
        }
        return true;
    }
    
    int minTime(vector<int>& arr, int k) {
        int n=arr.size();
       // if(n<k) return -1;//this line should not be there
        int s=0;
        int e=accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
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