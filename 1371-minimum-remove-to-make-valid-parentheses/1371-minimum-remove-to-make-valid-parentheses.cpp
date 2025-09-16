class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        for(int i=0;i<s.length();i++){
            if(isalpha(s[i])) continue;
            if(s[i]=='(')
            st.push(i);
            else{
                if(!st.empty()&&s[st.top()]=='('){
                    st.pop();
                }
                else
                st.push(i);
            }
        }
        unordered_map<int,bool>mpp;
        while(!st.empty()){
            int idx=st.top();
            st.pop();
            mpp[idx]=1;
        }
        string temp="";
        for(int i=0;i<s.length();i++){
            if(!mpp[i]){
                temp+=s[i];
            }
        }
        return temp;
    }
};