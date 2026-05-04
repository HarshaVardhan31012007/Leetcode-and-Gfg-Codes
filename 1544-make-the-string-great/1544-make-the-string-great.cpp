class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(!st.empty()&&(((st.top()-'A')==(s[i]-'a'))||((st.top()-'a')==(s[i]-'A')))){
                st.pop();
            }
            else
            st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};