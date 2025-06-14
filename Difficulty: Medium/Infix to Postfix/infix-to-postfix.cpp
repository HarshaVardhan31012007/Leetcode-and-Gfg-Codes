class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int priority(char ch){
        if(ch=='^'){
            return 3;
        }
        if(ch=='*'||ch=='/'){
            return 2;
        }
        else if(ch=='+'||ch=='-'){
            return 1;
        }
        else
        return -1;
    }
    string infixToPostfix(string& s) {
        stack<char>st; 
        string ans="";
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'||ch>='0'&&ch<='9'){
                ans=ans+ch;
            }
            else if(ch=='(')
            st.push(ch);
            else if(ch==')'){
                while(st.top()!='('){
                  ans=ans+st.top();
                  st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty()&&priority(ch)<=priority(st.top())){
                    ans=ans+st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while(!st.empty()){
            ans=ans+st.top();
            st.pop();
        }
        return ans;
    }
    
    
    //infix to prefix
    // void reverse(string &s){
    //     int i=0;
    //     int j=s.length()-1;
    //     while(i<=j){
    //         int temp=s[i];
    //         s[i]=s[j];
    //         s[j]=temp;
    //         i++;
    //         j--;
    //     }
    // }
    // string infixToPrefix(string& s) {
    //     stack<char>st; 
    //     reverse(s);
    //     string ans="";
    //     for(int i=0;i<s.length();i++){
    //         char ch=s[i];
    //         if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z'||ch>='0'&&ch<='9'){
    //             ans=ans+ch;
    //         }
    //         else if(ch=='(')
    //         st.push(ch);
    //         else if(ch==')'){
    //             while(st.top()!='('){
    //               ans=ans+st.top();
    //               st.pop();
    //             }
    //             st.pop();
    //         }
    //         else{
    //             if(ch=='^'){
    //             while(!st.empty()&&priority(ch)<priority(st.top())){
    //                 ans=ans+st.top();
    //                 st.pop();
    //             }
    //             }
    //             else{
    //                 while(!st.empty()&&priority(ch)<=priority(st.top())){
    //                 ans=ans+st.top();
    //                 st.pop();
    //             }
    //             }
    //             st.push(ch);
    //         }
    //     }
    //     while(!st.empty()){
    //         ans=ans+st.top();
    //         st.pop();
    //     }
    //     reverse(ans);
    //     return ans;
    //}
    
};