class Solution {
public:
    // vector<vector<string>> groupAnagrams(vector<string>& strs) {

    //     vector<vector<string>>v;
    //     unordered_map<string,vector<string>>mpp;

    //     for(int i=0;i<strs.size();i++){
    //         string curr=strs[i];
    //         sort(curr.begin(),curr.end());
    //         mpp[curr].push_back(strs[i]);
    //     }

    //     // for(auto each:mpp){
    //     //     v.push_back(each.second);
    //     // }
    //     for(auto it=mpp.begin();it!=mpp.end();it++){
    //         v.push_back(it->second);
    //     }
    //     return v;
    // }
   
     array<int,256>hash(string k){
        array<int,256>hash={0};
        for(int i=0;i<k.size();i++){
            hash[k[i]]++;
        }
        return hash;
     }
     vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>>v;// or std::array<int,256>
        map<array<int,256>,vector<string>>mpp;//here comparison function will be there
        //but for unordered_map we have to need hash function 

        for(int i=0;i<strs.size();i++){
            mpp[hash(strs[i])].push_back(strs[i]);
            }

        for(auto each:mpp){
            v.push_back(each.second);
        }
        return v;
    }
};