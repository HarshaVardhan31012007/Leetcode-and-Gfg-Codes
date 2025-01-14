//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string FirstNonRepeating(string &s) {
        int n=s.size();
        string ans="";
        unordered_map<char,int>count;
        queue<char>q;
        for(int i=0;i<n;i++){
            char ch=s[i];
            count[ch]++;
            q.push(ch);
            while(!q.empty()){
                // if(count[q.front()]>1){
                //     q.pop();
                // }
                // else{
                //   ans.push_back(q.front());
                //   break;//break is important
                // }
                
                 if(count[q.front()]==1){
                ans.push_back(q.front());
                   break;//break is important
                }
                else{
                  q.pop();
                  }
            }
            if(q.empty()){
                ans.push_back('#');
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends