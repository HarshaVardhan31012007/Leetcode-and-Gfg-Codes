class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.length();
        int i=0;int j=0;
        while(j<n){
            s[i++]=s[j];
            if(i>=k){
                bool same=true;
                for(int p=i-2;p>=i-k;p--){
                   if(s[p]!=s[p+1]){
                      same=false;
                      break;
                   }
                }
                if(same)
                i-=k;
            }
            j++;
        }
        return s.substr(0,i);
    }
};