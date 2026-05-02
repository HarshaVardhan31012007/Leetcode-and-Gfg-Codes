class Solution {
public:
    int solve(string &s,int k,char ch){
        int n=s.length();
        int i=0;
        int j=0;
        int changes=0;
        int ans=0;
        while(j<n){
            if(s[j]!=ch) changes++;
            if(changes>k){
                if(s[i]!=ch) changes--;
                i++;
            }
            if(changes<=k)
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
    int characterReplacement(string s, int k) {
        int ans=0;
        for(int i=0;i<26;i++){
            char ch=(i+'A');
            ans=max(ans,solve(s,k,ch));
        }
        return ans;
    }
};