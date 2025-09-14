// User function Template for C++

class Solution {
  public:
    void reverse(string &s){
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            swap(s[i],s[j]);
            // if(s[i]=='(') s[i]=')';
            // else if(s[i]==')') s[i]='(';
            // if(i!=j&&s[j]=='(') s[j]=')';
            // else if(i!=j&&s[j]==')') s[j]='(';
            i++;
            j--;
        }
    }
    string preToInfix(string pre_exp) {
        string exp=pre_exp;
        reverse(exp);
         stack<string>s;
        for(int i=0;i<exp.length();i++){
            if(isalpha(exp[i])){
                s.push(string(1,exp[i]));
            }
            else{
                string b=s.top();s.pop();
                string a=s.top();s.pop();
                s.push(")"+a+exp[i]+b+"(");
            }
        }
        reverse(s.top());
        return s.top();
    }
};