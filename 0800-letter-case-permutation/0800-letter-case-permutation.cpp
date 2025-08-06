class Solution {
public:
    void solve(string &s,int i,vector<string>&ans,string temp){
        if(i==s.length()){
            ans.push_back(temp);
            return;
        }
        if(isdigit(s[i]))
        solve(s,i+1,ans,temp+s[i]);
        else{
            char ch=toupper(s[i]);
            solve(s,i+1,ans,temp+ch);
            solve(s,i+1,ans,temp+(char)tolower(s[i]));
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        string temp="";
        solve(s,0,ans,temp);
        return ans;
    }
};