class Solution {
public:
    string removeDuplicates(string s) {
        // string ans="";
        // int n=s.length();
        // for(int i=0;i<n;i++){
        //     char c=s[i];
        //     if(ans.empty()||c!=ans.back()){
        //        ans.push_back(c);
        //     }
        //     else if(c==ans.back())
        //     ans.pop_back();
        // }
        // return ans;
        int i=0;int n=s.length();
        string x=s;
        for(int j=0;j<n;j++,i++){
            x[i]=s[j];
            if(i>0&&x[i]==x[i-1])
            i=i-2;
        }
        return x.substr(0,i);
    }
};