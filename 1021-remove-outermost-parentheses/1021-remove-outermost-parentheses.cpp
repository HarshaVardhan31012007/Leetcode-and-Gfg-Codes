class Solution {
public:
    string removeOuterParentheses(string s) {
        int c=0;
        string ans="";
        int start=0;
        for(int i=0;i<s.length();i++){
            if(c==0) start=i;
            if(s[i]=='(') c++;
            else c--;
            if(c==0){
               ans+=s.substr(start+1,i-start-1);
            }
        }
        return ans;
    }
};