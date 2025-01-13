//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
  //method 1
//   int findneg(queue<int>q){
//       if(q.empty()){
//           return 0;
//       }
//       if(q.front()<0){
//           return q.front();
//       }
//       q.pop();
//       return findneg(q);
//   }
    vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        //method 1
        // vector<int>ans;
        // queue<int>q;
        // //step1
        // //process first window
        // for(int i=0;i<k;i++){
        //     q.push(arr[i]);
        // }
        // //process for rem windows
        // for(int i=k;i<arr.size();i++){
        //     //ans ko process
        //     int Ans=findneg(q);
        //     ans.push_back(Ans);
        //     //removal
        //     q.pop();
        //     //add
        //     q.push(arr[i]);
        // }
        //  int Ans=findneg(q);
        // ans.push_back(Ans);
        // return ans;
        //method 2
        vector<int>ans;
        queue<int>q;
        int n=arr.size();
        //step1
        //process first window
        //store indices
        for(int i=0;i<k;i++){
            if(arr[i]<0)
            q.push(i);
        }
        //process for rem windows
        for(int i=k;i<n;i++){
            //ans store prev window ka
            if(q.empty()){
                ans.push_back(0);
            }
            else{
                ans.push_back(arr[q.front()]);
            }
            //removal
            if(!q.empty()&&i-q.front()>=k){
                q.pop();
            }
            //add
            if(arr[i]<0)
            q.push(i);
        }
        if(q.empty()){
                ans.push_back(0);
            }
          else{
                ans.push_back(arr[q.front()]);
          }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.FirstNegativeInteger(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends