class Solution {
public:
void solve(vector<string>&ans,int i,string &s){
    if(i==s.length()){
        ans.push_back(s);
        return;
    }
    if(isalpha(s[i])){
        s[i]=toupper(s[i]);
        solve(ans,i+1,s);
        s[i]=tolower(s[i]);
        solve(ans,i+1,s);
    }
    else
    solve(ans,i+1,s);
}
    vector<string> letterCasePermutation(string s) {
      vector<string>ans;
      solve(ans,0,s);
      return ans;
    }
};