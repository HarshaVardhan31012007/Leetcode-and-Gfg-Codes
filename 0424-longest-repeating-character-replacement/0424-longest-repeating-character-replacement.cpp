class Solution {
public:
    // int solve(string &s,int k,char ch){
    //     int n=s.length();
    //     int i=0;
    //     int j=0;
    //     int changes=0;
    //     int ans=0;
    //     while(j<n){
    //         if(s[j]!=ch) changes++;
    //         if(changes>k){
    //             if(s[i]!=ch) changes--;
    //             i++;
    //         }
    //         if(changes<=k)
    //         ans=max(ans,j-i+1);
    //         j++;
    //     }
    //     return ans;
    // }
    // int characterReplacement(string s, int k) {
    //     int ans=0;
    //     for(int i=0;i<26;i++){
    //         char ch=(i+'A');
    //         ans=max(ans,solve(s,k,ch));
    //     }
    //     return ans;
    // }


    // int characterReplacement(string s, int k) {
    //     int n=s.length();
    //     int freq[26]={0};
    //     int i=0;
    //     int j=0;
    //     int maxfreq=0;
    //     int ans=0;
    //     while(j<n){
    //         freq[s[j]-'A']++;
    //         maxfreq=max(maxfreq,freq[s[j]-'A']);
    //         while(((j-i+1)-maxfreq)>k){
    //             freq[s[i]-'A']--;
    //             maxfreq=0;
    //             for(int k=0;k<26;k++)
    //             maxfreq=max(maxfreq,freq[k]);
    //             i++;
    //         }
    //         if(((j-i+1)-maxfreq)<=k)
    //         ans=max(ans,j-i+1);
    //         j++;
    //     }
    //     return ans;
    // }



     int characterReplacement(string s, int k) {
        int n=s.length();
        int freq[26]={0};
        int i=0;
        int j=0;
        int maxfreq=0;
        int ans=0;
        while(j<n){
            freq[s[j]-'A']++;
            maxfreq=max(maxfreq,freq[s[j]-'A']);
            if(((j-i+1)-maxfreq)>k){
                freq[s[i]-'A']--;
                maxfreq=0;
                i++;
            }
            if(((j-i+1)-maxfreq)<=k)
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};