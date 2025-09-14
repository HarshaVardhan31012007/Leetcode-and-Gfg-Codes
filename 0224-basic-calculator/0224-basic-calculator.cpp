class Solution {
public:
    //  int power(char op){
    //     if(op==')') return 3;
    //     if(op=='+'||op=='-') return 1;
    //     if(op=='*'||op=='/') return 2;
    //     return -1;// for ( not to remove from stack 
    // }
    // int calculate(string s) {
    //     stack<int>st;
    //     stack<char>s1;
    //     bool flag=0;int ops=0;
    //     for(int i=0;i<s.length();i++){
    //           if(s[i]==' ') continue;
    //           else if(s[i]=='('){
    //             s1.push('(');
    //           }
    //           else if(isdigit(s[i])){
    //             int num=0;
    //             while(isdigit(s[i])){
    //                 num=num*10+(s[i]-'0');
    //                 i++;
    //             }
    //             st.push(num);
    //             i--;
    //           }
    //           else{
    //             if(s[i]!=')') ops++;
    //             if(ops>st.size()&&s[i]=='-'){
    //                st.push(0);
    //                s1.push('-');
    //                continue;
    //             }
    //             while((s[i]==')'&&s1.top()!='(')||(!s1.empty()&&power(s[i])<=power(s1.top()))){
    //                 int a=st.top();
    //                 st.pop();
    //                 int b=st.top();
    //                 st.pop();
    //                 char op=s1.top();
    //                 s1.pop();
    //                 ops--;
    //                  switch(op){
    //                 case '+':st.push(b+a);
    //                 break;
    //                 case '-':st.push(b-a);
    //                 break;
    //                 case '*':st.push(b*a);
    //                 break;
    //                 case '/':st.push(b/a);
    //                 break;
    //                 }
    //             }
    //             if(s[i]==')')
    //             s1.pop();
    //             else
    //             s1.push(s[i]);
    //           }
    //     }
    //             while(st.size()>1&&!s1.empty()){
    //                 int a=st.top();
    //                 st.pop();
    //                 int b=st.top();
    //                 st.pop();
    //                 char op=s1.top();
    //                 s1.pop();
    //                 switch(op){
    //                 case '+':st.push(b+a);
    //                 break;
    //                 case '-':st.push(b-a);
    //                 break;
    //                 case '*':st.push(b*a);
    //                 break;
    //                 case '/':st.push(b/a);
    //                 break;
    //                 }
    //             }
    //             if(s1.empty()) return st.top();
    //             if(s1.top()=='-') return -st.top();
    //             return -1;
    // }





      int calculate(string s){
          int result=0;
          int sign=1;
          int num=0;
          stack<int>st;
          for(int i=0;i<s.length();i++){
              if(isdigit(s[i]))
              num=num*10+(s[i]-'0');
              if(s[i]=='+'){
                   result+=sign*num;
                   sign=1;
                   num=0;
              }
              else if(s[i]=='-'){
                   result+=sign*num;
                   sign=-1;
                   num=0;
              }
              else if(s[i]=='('){
                  st.push(result);
                  st.push(sign);
                  result=0;
                  sign=1;
              }
              else if(s[i]==')'){
                 result+=sign*num;
                 int sign1=st.top();
                 st.pop();
                 result=st.top()+sign1*result;
                 st.pop();
                 sign=1;
                 num=0;
              }
          }
          result+=sign*num;
          return result;
      } 
};