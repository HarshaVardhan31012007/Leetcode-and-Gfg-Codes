class Solution {
public:
    string removeDuplicates(string s) {
        // string ans="";
        // for(int i=0;i<s.length();i++){
        //     if(ans.empty()||ans.back()!=s[i])
        //     ans.push_back(s[i]);
        //     else
        //     ans.pop_back();
        // }
        // return ans;


        int i=0;int n=s.length();
        for(int j=0;j<n;j++,i++){
            s[i]=s[j];
            if(i>0&&s[i]==s[i-1])
            i=i-2;
        }
        return s.substr(0,i);
    }
};