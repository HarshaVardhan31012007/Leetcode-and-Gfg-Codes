class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(auto &each:words){
            long long sum=0;
            for(auto &ch:each){
                sum+=weights[ch-'a'];
            }
            sum=sum%26;
            ans+=(25-sum+'a');
        }
        return ans;
    }
};