class Solution {
  public:
    bool checkRedundancy(string &s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(!st.empty()&&st.top()=='(')
                return true;
                while(st.top()!='('){
                    st.pop();
                }
                st.pop();
            }
            else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
                st.push(s[i]);
            }
        }
        return false;
    }
};
