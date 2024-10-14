//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int firstRepeated(vector<int> &nums) {
         int n=nums.size();
        //  sort(nums.begin(),nums.end());
        // int ans=-1;
        //  for(int i=0;i<n;i++){
        //      if(nums[i]==nums[i+1]){
        //          ans=i+1;
        //          break;
        //      }
        //  }
        //  return ans;
        
        
    //int ans=-1;
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(nums[i]==nums[j])
    //                 ans=i+1;
    //         }
    //         if(ans==i+1)
    //         break;
    // }
    // return ans;
    
    
    // for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             if(nums[i]==nums[j])
    //                 return i+1;
    //         }
    // }
    // return ans;
    //  }
    
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        int a=nums[i];
        mpp[a]=mpp[a]+1;
    }
    for(int i=0;i<n;i++){
        if(mpp[nums[i]]>1)
        return i+1;
    }
       return -1;
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
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.firstRepeated(arr) << endl;
    }

    return 0;
}

// } Driver Code Ends