class Solution {
public:
    string removeOuterParentheses(string s) {
        // int c=0;
        // string ans="";
        // for(int i=0;i<s.length();i++){
        //     if(c!=0) ans+=s[i];
        //     if(s[i]=='(') c++;
        //     else c--;
        //     if(c==0){
        //        ans.pop_back();
        //     }
        // }
        // return ans;


        int c=0;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(c>0) ans+=s[i];
                c++;
            }
            else{
                c--;
                if(c>0) ans+=s[i];
            }
        }
        return ans;
    }
};