class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=s.length();
        vector<long long>suffix(n,0);
        suffix[n-1]=shifts[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=shifts[i]+suffix[i+1];
        }
        for(int i=0;i<n;i++){
           int curr=s[i]-'a';
           curr=(curr+suffix[i])%26;
           char ch=curr+'a';
           s[i]=ch;
        }
        return s;
    }
};