//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string& s) {
        //method 1
        //sort
        //map
        //method 2
        //arrays
        //sort
        int arr[26]={0};
        for(int i=0;i<s.length();i++){
            int number=0;
            number=s[i]-'a';
            arr[number]++;
        }
        int maxi=-1;
        int ans=0;
        for(int i=0;i<26;i++){
            if(arr[i]>maxi){
                ans=i;
                maxi=arr[i];
            }
        }
        char finalAns=ans+'a';
        return finalAns;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution obj;
        cout << obj.getMaxOccuringChar(str) << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends