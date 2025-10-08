class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
         sort(potions.begin(),potions.end());
         vector<int>ans;
         for(int i=0;i<spells.size();i++){
              int count=potions.end()-lower_bound(potions.begin(),potions.end(),((double)success)/spells[i]);
              ans.push_back(count);
         }
         return ans;
    }
};