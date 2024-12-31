//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s){
        stack<char>st;int count=0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
         
            if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('){
                st.push(ch);
            }
            if(ch==')'&&!st.empty()){
                if(st.top()=='('){
                   st.pop();
                   return 1;
                }
                else{
                    while(st.top()!='('){
                        st.pop();
                    }
                    st.pop();
                }
            }
            
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {

        string s;
        cin >> s;

        Solution obj;
        int res = obj.checkRedundancy(s);

        cout << res << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends