class Solution {
public:
    bool solve(string &s,string &p,int i,int j){
      if(i==s.length()&&j==p.length()) return 1;
      if(j==p.length()) return 0;
      bool curr=i<s.length()&&(p[j]=='.'||s[i]==p[j]);
      if(j+1<p.length()&&p[j+1]=='*'){
        int emptycase=solve(s,p,i,j+2);
        int precase=curr&&solve(s,p,i+1,j);
        return emptycase||precase;
      }
      else if(curr)
      return solve(s,p,i+1,j+1);
      else
      return false;
    }
    bool isMatch(string s, string p) {
        return solve(s,p,0,0);
    }
};