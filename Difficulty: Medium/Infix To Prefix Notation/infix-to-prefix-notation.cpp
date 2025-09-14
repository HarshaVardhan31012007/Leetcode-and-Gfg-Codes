class Solution {
  public:
    void reverse(string &s){
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            if(s[i]=='(') s[i]=')';
            else if(s[i]==')') s[i]='(';
            if(i!=j&&s[j]=='(') s[j]=')';
            else if(i!=j&&s[j]==')') s[j]='(';
            i++;
            j--;
        }
    }
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
    string infixToPrefix(string& s) {
        stack<char>st; 
        reverse(s);
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
                if(ch=='^'){
                while(!st.empty()&&priority(ch)<=priority(st.top())){
                    ans=ans+st.top();
                    st.pop();
                }
                }
                else{
                    while(!st.empty()&&priority(ch)<priority(st.top())){
                    ans=ans+st.top();
                    st.pop();
                }
                }
                st.push(ch);
            }
        }
        while(!st.empty()){
            ans=ans+st.top();
            st.pop();
        }
        reverse(ans);
        return ans;
    }
};
