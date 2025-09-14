// User function Template for C++

class Solution {
  public:
    void reverse(string &s){
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    string preToPost(string exp) {
          reverse(exp);
         stack<string>s;
         for(int i=0;i<exp.length();i++){
             if(isalpha(exp[i])){
                 s.push(string(1,exp[i]));
             }
             else{
                string b=s.top();s.pop();
                string a=s.top();s.pop();
                s.push(exp[i]+a+b);
             }
         }
         reverse(s.top());
         return s.top();
    }
};