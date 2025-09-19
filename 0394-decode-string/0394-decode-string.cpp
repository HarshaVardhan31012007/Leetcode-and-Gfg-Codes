class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(int i=0;i<s.length();i++){
          if(s[i]==']'){
                string temp="";
                while(st.top()[0]!='['){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                string num="";
                while(!st.empty()&&isdigit(st.top()[0])){
                    num=st.top()+num;
                    st.pop();
                }
                int n=stoi(num);
                string decode="";
                while(n--){
                    decode=decode+temp;
                }
                st.push(decode);
          }
          else{
             string temp(1,s[i]);
             st.push(temp);
          }
        }
        string ans="";
        while(!st.empty()){
            ans=ans+st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};