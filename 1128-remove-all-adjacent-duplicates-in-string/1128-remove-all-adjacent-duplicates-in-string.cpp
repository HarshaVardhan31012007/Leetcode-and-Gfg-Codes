class Solution {
public:
    string removeDuplicates(string x) {
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

        int i=0;int n=x.length();
        for(int j=0;j<n;j++,i++){
            x[i]=x[j];
            if(i>0&&x[i]==x[i-1])
            i=i-2;
        }
        return x.substr(0,i);
    }
};