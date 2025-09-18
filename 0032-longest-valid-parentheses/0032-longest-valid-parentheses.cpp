class Solution {
public:
    int longestValidParentheses(string s) {
        // stack<int>st;
        // st.push(-1);
        // for(int i=0;i<s.length();i++){
        //     if(s[i]=='(')
        //     st.push(i);
        //     else{
        //         if(!st.empty()&&st.top()!=-1&&s[st.top()]=='('){
        //            st.pop();
        //         }
        //         else{
        //             st.push(i);
        //         }
        //     }
        // }
        // st.push(s.length());
        // int maxi=INT_MIN;
        // while(st.size()>1){
        //     int b=st.top();
        //     st.pop();
        //     int a=st.top();
        //     maxi=max(maxi,b-a-1);
        // }
        // return maxi;



        stack<int>st;
        st.push(-1);
        int maxi=INT_MIN;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
            st.push(i);
            else{
              st.pop();
              if(st.empty()){
                 st.push(i);
              }
              else{
                 int curr=i-st.top();
                 maxi=max(maxi,curr);
              }
            }
        }
        return maxi==INT_MIN?0:maxi;
    }
};