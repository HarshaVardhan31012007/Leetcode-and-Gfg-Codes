class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            char c=s[i];
            if(ans.empty()||c!=ans.back()){
               ans.push_back(c);
            }
            else if(c==ans.back())
            ans.pop_back();
        }
        return ans;
    }
};