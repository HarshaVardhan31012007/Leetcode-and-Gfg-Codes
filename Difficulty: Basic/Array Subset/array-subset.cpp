class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        unordered_map<int,int>freq;
        for(auto &each:a)
        freq[each]++;
        for(auto &each:b){
            if(freq[each]>0)
            freq[each]--;
            else
            return false;
        }
        return true;
    }
};