class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,int>mpp;
        for(auto &each:patterns)
        mpp[each]++;
        int n=word.length();
        int ans=0;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=i;j<n;j++){
                temp+=word[j];
                if(mpp.count(temp)){
                    ans+=mpp[temp];
                    mpp.erase(temp);
                }
            }
        }
        return ans;
    }
};