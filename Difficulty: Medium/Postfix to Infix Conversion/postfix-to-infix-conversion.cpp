// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        stack<string>s;
        for(int i=0;i<exp.length();i++){
            if(isalpha(exp[i])){
                s.push(string(1,exp[i]));
            }
            else{
                string b=s.top();s.pop();
                string a=s.top();s.pop();
                s.push("("+a+exp[i]+b+")");
            }
        }
        return s.top();
    }
};