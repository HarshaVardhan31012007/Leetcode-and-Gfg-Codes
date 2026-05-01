class Solution {
public:
    // int solve(string &s,int k){
    //     int i=0;
    //     int j=0;
    //     int n=s.length();
    //     unordered_map<int,int>mpp;
    //     int count=0;
    //     while(j<n){
    //        mpp[s[j]]++;
    //        while(mpp.size()>k){
    //          mpp[s[i]]--;
    //          if(mpp[s[i]]==0) mpp.erase(s[i]);
    //          i++;
    //        }
    //        count+=(j-i+1);
    //        j++;
    //     }
    //     return count;
    // }
    // int numberOfSubstrings(string s) {
    //     return solve(s,3)-solve(s,2);
    // }



    int solve(string &s,int k){
        int i=0;
        int j=0;
        int n=s.length();
        int a=0;int b=0;int c=0;
        int count=0;
        while(j<n){
           if(s[j]=='a') a++;
           else if(s[j]=='b') b++;
           else if(s[j]=='c') c++;
           while(a!=0&&b!=0&&c!=0){
              if(s[i]=='a') a--;
              else if(s[i]=='b') b--;
              else if(s[i]=='c') c--;
              i++;
           }
           count+=(j-i+1);
           j++;
        }
        return count;
    }
    int numberOfSubstrings(string s) {
        int n=s.length();
        return (1LL*n*(n+1))/2-solve(s,2);
    }
};