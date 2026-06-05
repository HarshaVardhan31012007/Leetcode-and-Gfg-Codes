class Solution {
public:
    // string decodeString(string s) {
    //     int n=s.length();
    //     stack<string>st;
    //     for(int i=0;i<n;i++){
    //        if(s[i]==']'){
    //           string temp="";
    //           while(!st.empty()&&st.top()!="["){
    //                temp+=st.top();
    //                st.pop();
    //           }
    //           st.pop();
    //           int num=0;int c=1;
    //           while(!st.empty()&&isdigit(st.top()[0])){
    //              num+=c*(st.top()[0]-'0');
    //              st.pop();
    //              c=c*10;
    //           }
    //           string temp1="";
    //           while(num>0){
    //             temp1+=temp;
    //             num--;
    //           }
    //           st.push(temp1);
    //        }
    //        else
    //        st.push(string(1,s[i]));
    //     }
    //     string ans="";
    //     while(!st.empty()){
    //         ans+=st.top();
    //         st.pop();
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    // }


    string helper(string &s,int &i,int n){
        string temp="";
        while(i<n){
            int num=0;
            while(i<s.length()&&isdigit(s[i])){
                num=num*10+(s[i]-'0');
                i++;
            }
            while(i<s.length()&&islower(s[i])){
                temp+=s[i];
                i++;
            }
            if(i==n) return temp;
            if(s[i]=='['){
                i++;
                string rec=helper(s,i,n);
                while(num>0){
                    temp+=rec;
                    num--;
                }
            }
            else if(s[i]==']'){
                i++;
                return temp;
            }
        }
        return temp;
    }
    string decodeString(string s) {
        int n=s.length();
        int i=0;
        return helper(s,i,n);
    }
};