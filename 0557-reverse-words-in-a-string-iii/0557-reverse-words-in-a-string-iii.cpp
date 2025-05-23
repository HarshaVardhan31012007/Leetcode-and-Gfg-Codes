class Solution {
public:
    string reverseWords(string s) {
        // string ans="";
        // string temp="";
        // for(int i=0;i<s.length();i++){
        //     if(s[i]==' '){
        //         reverse(temp.begin(),temp.end());
        //         ans=ans+temp+s[i];
        //         temp="";
        //     }
        //     else{
        //         temp.push_back(s[i]);
        //     }
        // }
        // reverse(temp.begin(),temp.end());
        // ans=ans+temp;
        // return ans;

        int i=0;
        int j;
        for(j=0;j<s.length();j++){
              if(s[j]==' '){
              reverse(s.begin()+i,s.begin()+j);
              i=j+1;
              }
        }
        reverse(s.begin()+i,s.begin()+j);
        return s;
    }
};