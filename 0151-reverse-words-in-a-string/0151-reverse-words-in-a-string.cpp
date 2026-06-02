class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans="";
        string temp="";
        for(int j=n-1;j>=0;j--){
           if(s[j]!=' '){
              temp+=s[j];
           }
           if(j==0||(s[j]==' ')){
              if(!temp.empty()){
                reverse(temp.begin(),temp.end());
                ans+=temp+" ";
                temp="";
              }
           }
        }
        if(!ans.empty()&&ans.back()==' ') ans.pop_back();
        return ans;
    }
};