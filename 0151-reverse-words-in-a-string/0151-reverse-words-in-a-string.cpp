class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int i=0;int j=0;
        for(int k=0;k<s.length();k++){
            while(k<s.length()&&s[k]==' ') k++;
            if(k==s.length()) break;
            while(k<s.length()&&s[k]!=' '){
                s[j++]=s[k++];
            }
            reverse(s.begin()+i,s.begin()+j);
            s[j++]=' ';
            i=j;
        }
        s.resize(j-1);
        return s;
    }
};