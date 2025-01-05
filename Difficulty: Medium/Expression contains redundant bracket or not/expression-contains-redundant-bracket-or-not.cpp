//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int checkRedundancy(string s){
        // stack<char>st;
        // for(int i=0;i<s.length();i++){
        //     char ch=s[i];
         
        //     if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('){
        //         st.push(ch);
        //     }
        //     if(ch==')'&&!st.empty()){
        //         if(st.top()=='('){//(ab) in this case this code fails but this is not a valid testcases
        //           st.pop();
        //           return 1;
        //         }
        //         else{//it only comes when it is not redundant like when blw brackets operators are there
        //             while(st.top()!='('){
        //                 st.pop();
        //             }
        //             st.pop();
        //         }
        //     }
            
        // }
        
        
        
        //if you want to consider that above (ab) case also
        //follow this
        stack<char>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
         
            if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('){
                st.push(ch);
            }
            else{
                if(ch==')'&&!st.empty()){
                    bool isReduntant=true;
                    while(st.top()!='('){
                        if(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/'){
                            isReduntant=false;
                        }
                        st.pop();
                    }
                    if(isReduntant==true)
                    return true;
                    st.pop();
                 }
                }
        }
        return false;
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