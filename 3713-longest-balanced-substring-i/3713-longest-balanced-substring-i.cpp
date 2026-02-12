class Solution {
public:
    int longestBalanced(string s) {
        // int n=s.length();
        // int ans=0;
        // for(int i=0;i<s.length();i++){
        //     int freq[26]={0};
        //     for(int j=i;j<s.length();j++){
        //         freq[s[j]-'a']++;
        //         int mini=INT_MAX;int maxi=INT_MIN;
        //         for(int k=0;k<26;k++){
        //             if(freq[k]==0) continue;
        //             maxi=max(maxi,freq[k]);
        //             mini=min(mini,freq[k]);
        //         }
        //         if(mini==maxi){
        //                 ans=max(ans,j-i+1);
        //         }
        //     }
        // }
        // return ans;



        int n=s.length();
        int ans=0;
        for(int i=0;i<s.length();i++){
            int freq[26]={0};int dist=0;int maxi=INT_MIN;
            for(int j=i;j<s.length();j++){
                if(freq[s[j]-'a']==0) dist++;
                freq[s[j]-'a']++;
                maxi=max(maxi,freq[s[j]-'a']);
                int len=j-i+1;
                if(len==maxi*dist)
                ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};