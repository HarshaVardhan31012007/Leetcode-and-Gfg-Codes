class Solution {
public:
    string processStr(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                ans+=s[i];
            }
            else if(s[i]=='#'){
                ans+=ans;
            }
            else if(s[i]=='*'){
                if(!ans.empty()) ans.pop_back();
            }
            else
            reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};