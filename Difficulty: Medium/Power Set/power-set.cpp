class Solution {
  public:
    vector<string> AllPossibleStrings(string s) {
       int len=s.length();
       int n=1<<len;
       vector<string>ans;
       for(int num=1;num<n;num++){
           string temp="";
           for(int i=len-1;i>=0;i--){
               int mask=1<<i;
               if(num&mask)
               temp=s[i]+temp;
           }
           ans.push_back(temp);
       }
       sort(ans.begin(),ans.end());
       return ans;
    }
};