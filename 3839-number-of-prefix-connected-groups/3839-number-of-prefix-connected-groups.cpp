class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int>mpp;
        int ans=0;
        for(int i=0;i<words.size();i++){
            if(words[i].length()<k) continue;
            string temp=words[i].substr(0,k);
            if(mpp.count(temp)){
                if(mpp[temp]==1)
                ans++;
            }
            mpp[temp]++;
        }
        return ans;
    }
};