class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int beautysum=0;
        unordered_map<char,int>mpp;
              for (int i = 0; i < n; i++) {
                mpp.clear();
            for (int j = i; j < n; j++) {
                 char ch=s[j];
                 mpp[ch]++;
                 int maxi=INT_MIN;
                 int mini=INT_MAX;
                 for(auto each: mpp){
                    maxi=max(maxi,each.second);
                    mini=min(mini,each.second);
                 }
                 int beauty=maxi-mini;
                 beautysum+=beauty;
            }
        }
        return beautysum;
    }
};