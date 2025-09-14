// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
         stack<string>s;
         for(int i=0;i<post_exp.length();i++){
             if(isalpha(post_exp[i])){
                 s.push(string(1,post_exp[i]));
             }
             else{
                string b=s.top();s.pop();
                string a=s.top();s.pop();
                s.push(post_exp[i]+a+b);
             }
         }
         return s.top();
    }
};