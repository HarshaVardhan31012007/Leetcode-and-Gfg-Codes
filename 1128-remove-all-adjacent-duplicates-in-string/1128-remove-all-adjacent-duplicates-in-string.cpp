class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            bool flag=1;
            while(!st.empty()&&st.top()==s[i]){
                flag=0;
                st.pop();
            }
            if(flag)
            st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};