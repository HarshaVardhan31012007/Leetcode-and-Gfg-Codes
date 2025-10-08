class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
         sort(potions.begin(),potions.end());
         vector<int>ans;
         for(int i=0;i<spells.size();i++){
              int count=potions.end()-lower_bound(potions.begin(),potions.end(),((double)success)/spells[i]);// double is imp because potions 1 2 3 4 5 and spells 5 1 3 if you take 7/5=1 but here 1 should not accept so take double
              ans.push_back(count);
         }
         return ans;
    }
};