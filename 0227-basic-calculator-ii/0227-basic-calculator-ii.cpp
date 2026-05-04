class Solution {
public:
    int priority(char ch){
        if(ch=='*'||ch=='/') return 2;
        return 1;
    }
    int calculate(string s) {
        stack<int>st1;
        stack<char>st2;
        int n=s.length();
        int i=0;
        while(i<n){
            int num=0;
            if(isdigit(s[i])){
                while(i<n&&isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                st1.push(num);
            }
            else if(s[i]!=' '){
                while(!st2.empty()&&priority(s[i])<=priority(st2.top())){
                    int b=st1.top();
                    st1.pop();
                    int a=st1.top();
                    st1.pop();
                    char ch=st2.top();
                    st2.pop();
                    if(ch=='+'){
                        st1.push(a+b);
                    }
                    else if(ch=='-'){
                        st1.push(a-b);
                    }
                    else if(ch=='*'){
                        st1.push(a*b);
                    }
                    else if(ch=='/'){
                        st1.push(a/b);
                    }
                }
                st2.push(s[i]);
                i++;
            }
            else
            i++;
        }
        int ans=0;
        while(!st1.empty()&&!st2.empty()&&st1.size()>=2&&st2.size()>=1){
            int b=st1.top();
            st1.pop();
            int a=st1.top();
            st1.pop();
            char ch=st2.top();
            st2.pop();
            if(ch=='+'){
                st1.push(a+b);
            }
            else if(ch=='-'){
                st1.push(a-b);
            }
            else if(ch=='*'){
                st1.push(a*b);
            }
            else if(ch=='/'){
                st1.push(a/b);
            }
        }
        return st1.top();
    }
};