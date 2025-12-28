class Solution {
public:
    string check(string &s,int i,int j){
        while(i>=0&&j<s.length()){
            if(s[i]==s[j]){
                i--;j++;
            }
            else
            break;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            string temp=check(s,i,i);
            if(temp.length()>ans.length()) ans=temp;
            temp=check(s,i,i+1);
            if(temp.length()>ans.length()) ans=temp;
        }
        return ans;
    }
};