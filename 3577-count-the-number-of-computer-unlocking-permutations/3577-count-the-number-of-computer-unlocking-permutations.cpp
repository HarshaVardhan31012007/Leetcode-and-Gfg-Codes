class Solution {
public:
    const int mod=1e9+7;
    int countPermutations(vector<int>& complexity) {
        // long long ans=1;
        // int fcomplex=complexity[0];
        // int mini=fcomplex;
        // for(int i=1;i<complexity.size();i++){
        //      if(mini>=complexity[i]) return 0;
        //      ans=(ans*i)%mod;
        //      mini=min(mini,complexity[i]);
        // }
        // return ans;


        long long ans=1;
        for(int i=1;i<complexity.size();i++){
             if(complexity[i]<=complexity[0]) return 0;
             ans=(ans*i)%mod;
        }
        return ans;
    }
};