class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n=words.size();
        int m=words[0].length();
        unordered_map<string,int>mpp;
        long long ans=0;
        for(int i=0;i<n;i++){
            for(int k=0;k<26;k++){
                string s="";
                for(int j=0;j<m;j++){
                    char ch=((words[i][j]-'a'+k)%26)+'a';
                    s+=ch;
                }
                if(mpp.count(s))
                    ans+=mpp[s];
            }
            mpp[words[i]]++;
        }
        return ans;
    }
};