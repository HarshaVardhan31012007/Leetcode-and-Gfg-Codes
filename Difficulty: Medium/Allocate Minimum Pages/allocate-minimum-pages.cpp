//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool possible(vector<int>&arr,int n,int k,int sol){//sol means solution
        int pageSum=0;
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
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(n<k) return -1;
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
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends