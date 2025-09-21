class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(int i=0;i<num.length();i++){
             int curr=num[i]-'0';
             while(!st.empty()&&k>0&&st.top()>curr){
                st.pop();
                k--;
             }
             st.push(curr);
        }
        while(!st.empty()&&k>0){
            st.pop();
            k--;
        }
        string ans="";
            // while(!st.empty()){
            //     char ch=st.top()+'0';
            //     ans=ch+ans; // MLE caused by this
            //     st.pop();
            // }
        while(!st.empty()){
            char ch=st.top()+'0';
            ans+=ch;
            st.pop();
        }
        while(!ans.empty()&&ans.back()=='0')
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans==""?"0":ans;
    }
};