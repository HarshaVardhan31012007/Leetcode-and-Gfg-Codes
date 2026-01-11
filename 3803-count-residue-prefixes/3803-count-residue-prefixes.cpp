class Solution {
public:
    // int residuePrefixes(string s) {
    //     int c=0;int ans=0;
    //     unordered_map<int,int>mpp;
    //     for(int i=0;i<s.length();i++){
    //         if(!mpp.count(s[i]))
    //             c++;
    //         if(c==((i+1)%3))
    //             ans++; 
    //         mpp[s[i]]=1;
    //     }
    //     return ans;
    // }


    // int residuePrefixes(string s) {
    //     int c=0;int ans=0;
    //     int freq[26]={0};
    //     for(int i=0;i<s.length();i++){
    //         if(freq[s[i]-'a']==0)
    //             c++;
    //         if(c==((i+1)%3))
    //             ans++; 
    //         freq[s[i]-'a']++;
    //     }
    //     return ans;
    // }


    int residuePrefixes(string s) {
        int c=0;int ans=0;
        bool freq[26]={0};
        for(int i=0;i<s.length();i++){
            if(freq[s[i]-'a']==0)
                c++;
            if(c==((i+1)%3))
                ans++; 
            freq[s[i]-'a']=1;
        }
        return ans;
    }
};