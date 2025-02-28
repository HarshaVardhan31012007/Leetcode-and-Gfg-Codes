class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>>v;
        unordered_map<string,vector<string>>mpp;

        for(int i=0;i<strs.size();i++){
            string curr=strs[i];
            sort(curr.begin(),curr.end());
            mpp[curr].push_back(strs[i]);
        }

        // for(auto each:mpp){
        //     v.push_back(each.second);
        // }
        for(auto it=mpp.begin();it!=mpp.end();it++){
            v.push_back(it->second);
        }
        return v;
    }
};