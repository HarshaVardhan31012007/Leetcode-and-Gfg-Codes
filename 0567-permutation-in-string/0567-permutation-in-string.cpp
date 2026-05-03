class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        int m=s1.length();
        int n=s2.length();
        int freq[26]={0};
        for(auto &each:s1)
        freq[each-'a']++;
        int count=m;
        for(int j=0;j<m;j++){
            if(freq[s2[j]-'a']>0) count--;
            freq[s2[j]-'a']--;
        }
        if(count==0)
        return true;
        for(int k=m;k<n;k++){
            freq[s2[k-m]-'a']++;
            if(freq[s2[k-m]-'a']>0) count++;
            if(freq[s2[k]-'a']>0) count--;
            freq[s2[k]-'a']--;
            if(count==0)
            return true;
        }
        return false;
    }
};