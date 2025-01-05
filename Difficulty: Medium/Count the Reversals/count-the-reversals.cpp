//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    
cout << "~" << "\n";
}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{   if(s.size() & 1)
    return -1;
    stack<int>st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='{'){
            st.push(s[i]);
        }
        else{
            if(!st.empty()&&s[i]=='}'&&st.top()=='{'){// no need of s[i]==')'
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
    }
        int ans=0;
        while(!st.empty()){
            char a=st.top();
            st.pop();
            char b=st.top();
            st.pop();
            if(a==b)
            ans=ans+1;
            else
            ans=ans+2;
        }
        return ans;
    }
