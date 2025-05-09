class Solution {
public:
    bool checkPalindrome(string &k,int i,int j){
        while(i<j){
            if(k[i]!=k[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                 if(checkPalindrome(s,i,j)){
                    string k=s.substr(i,j-i+1);
                    ans=k.length()>ans.length()?k:ans;
                 }
            }
        }
        return ans;
    }


    // string solve(string &s,int i,int j){
    //   if(i>j) return "";
    //   if(i==j){
    //     string k="";
    //     k+=s[i];
    //     return k;
    //   } 
    //   if(s[i]==s[j])
    //   return s[i]+solve(s,i+1,j-1)+s[j];
    //   else{
    //     string a=solve(s,i+1,j);string b=solve(s,i,j-1);
    //     if(a.length()<b.length()) return b;
    //     else return a;
    //   }
    // }
    // string longestPalindrome(string s) {
    //    int n=s.length();
    //    return solve(s,0,n-1);
    // }
};