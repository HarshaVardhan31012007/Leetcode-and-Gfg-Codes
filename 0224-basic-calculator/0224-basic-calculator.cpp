class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int result=0;
        int num=0;
        int sign=1;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0'&&s[i]<='9'){
               num=num*10+(s[i]-'0');
            }
            else if(s[i]=='+'){
                result=result+num*sign;
                sign=1;
                num=0;
            }
            else if(s[i]=='-'){
                result=result+num*sign;
                sign=-1;
                num=0;
            }
            else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
              //  num=0;//no need
            }
            else if(s[i]==')'){
                result+=sign*num;
                num=0;
                result*=st.top();
                st.pop();
                result+=st.top();
                st.pop();
            }
        }
        result+=sign*num;

        return result;
    }
};