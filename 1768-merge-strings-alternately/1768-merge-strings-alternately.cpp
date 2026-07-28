class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1=word1.length();
        int n2=word2.length();
        int i=0;
        string ans="";
        while(i<max(n1,n2)){
           if(i<n1)
           ans+=word1[i];
           if(i<n2)
           ans+=word2[i];
           i++;
        }
        // ans+=word1.substr(i);
        // ans+=word2.substr(j);
        return ans;
    }
};