class Solution {
public:
    string removeOuterParentheses(string s) {
        int c=0;
        string ans="";string temp="";
        for(int i=0;i<s.length();i++){
            if(c!=0) temp+=s[i];
            if(s[i]=='(') c++;
            else c--;
            if(c==0){
               temp.pop_back();
               ans+=temp;
               temp="";
            }
        }
        return ans;
    }
};