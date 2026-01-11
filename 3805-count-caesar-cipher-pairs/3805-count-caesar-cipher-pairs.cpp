class Solution {
public:
    long long countPairs(vector<string>& words) {
        // int n=words.size();
        // int m=words[0].length();
        // unordered_map<string,int>mpp;
        // long long ans=0;
        // for(int i=0;i<n;i++){
        //     for(int k=0;k<26;k++){
        //         string s="";
        //         for(int j=0;j<m;j++){
        //             char ch=((words[i][j]-'a'+k)%26)+'a';
        //             s+=ch;
        //         }
        //         if(mpp.count(s))
        //             ans+=mpp[s];
        //     }
        //     mpp[words[i]]++;
        // }
        // return ans;



        int n=words.size();
        int m=words[0].length();
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            int rot=words[i][0]-'a';
            for(auto &each:words[i]){
                each='a'+((each-'a')-rot+26)%26;
            }
            mpp[words[i]]++;
        }
        long long ans=0;
        for(auto &each:mpp){
            ans+=(1LL*(each.second)*(each.second-1))/2;
        }
        return ans;
    }
};