class Solution {
public:
    // int power(char op){
    //     if(op=='+'||op=='-') return 1;
    //     if(op=='*'||op=='/') return 2;
    //     return -1;
    // }
    // int calculate(string s) {
    //     stack<int>st;
    //     stack<char>s1;
    //     for(int i=0;i<s.length();i++){
    //           if(s[i]==' ') continue;
    //           if(isdigit(s[i])){
    //             int num=0;
    //             while(isdigit(s[i])){
    //                 num=num*10+(s[i]-'0');
    //                 i++;
    //             }
    //             st.push(num);
    //             i--;
    //           }
    //           else{
    //             while(!s1.empty()&&power(s[i])<=power(s1.top())){
    //                 int a=st.top();
    //                 st.pop();
    //                 int b=st.top();
    //                 st.pop();
    //                 char op=s1.top();
    //                 s1.pop();
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
    //                 cout<<a<<" "<<b<<" "<<op<<endl;
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
    //           return st.top();
    // }

     int calculate(string &s){
          int num=0;
          int op='+';
          stack<int>st;
          for(int i=0;i<s.length();i++){
              if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
              }
              if(i==s.length()-1||(!isdigit(s[i])&&s[i]!=' ')){
                 if(op=='+'){
                     st.push(num);
                     num=0;
                 }
                 else if(op=='-'){
                    st.push(-num);
                    num=0;
                 }
                 else if(op=='*'){
                    int prevnum=st.top();
                    st.pop();
                    st.push(prevnum*num);
                    num=0;
                 }
                 else if(op=='/'){
                    int prevnum=st.top();
                    st.pop();
                    st.push(prevnum/num);
                    num=0;
                 }
                 op=s[i];
              }
          }
              int result=0;
              while(!st.empty()){
                result+=st.top();
                st.pop();
              }
              return result;
     }
};