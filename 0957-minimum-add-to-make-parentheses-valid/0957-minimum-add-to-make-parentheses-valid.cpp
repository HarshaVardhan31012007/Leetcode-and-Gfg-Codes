class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        // for(int i=0;i<s.length();i++){
        //     if(s[i]=='('){
        //         st.push(s[i]);
        //     }
        //     else{
        //         if(!st.empty()&&st.top()=='(')
        //         st.pop();
        //         else
        //         st.push(s[i]);
        //     }
        // }
        // return st.size();

        //  int ans=0;
        //  for(int i=0;i<s.length();i++){
        //     if(s[i]=='('){
        //         st.push(s[i]);
        //         ans++;
        //     }
        //     else{
        //         if(!st.empty()&&st.top()=='('){
        //         st.pop();
        //         ans--;
        //         }
        //         else{
        //         st.push(s[i]);
        //         ans++;
        //         }
        //     }
        // }
        // return ans;


         int ans=0;
         for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                st.pop();
                }
                else{
                ans++;
                }
            }
        }
        return ans+st.size();
    }
};