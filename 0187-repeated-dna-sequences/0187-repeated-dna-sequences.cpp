class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mpp;
        vector<string>ans;
        for(int i=0;i<=(int)s.length()-10;i++){
            string curr=s.substr(i,10);
            mpp[curr]++;
            if(mpp[curr]==2)
            ans.push_back(curr);
        }
        return ans;
    }
};