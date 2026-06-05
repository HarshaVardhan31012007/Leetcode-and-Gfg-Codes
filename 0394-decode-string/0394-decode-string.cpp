class Solution {
public:
    string decodeString(string s) {
        int n=s.length();
        stack<string>st;
        for(int i=0;i<n;i++){
           if(s[i]==']'){
              string temp="";
              while(!st.empty()&&st.top()!="["){
                   temp+=st.top();
                   st.pop();
              }
              st.pop();
              int num=0;int c=1;
              while(!st.empty()&&isdigit(st.top()[0])){
                 num+=c*(st.top()[0]-'0');
                 st.pop();
                 c=c*10;
              }
              string temp1="";
              while(num>0){
                temp1+=temp;
                num--;
              }
              st.push(temp1);
           }
           else
           st.push(string(1,s[i]));
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