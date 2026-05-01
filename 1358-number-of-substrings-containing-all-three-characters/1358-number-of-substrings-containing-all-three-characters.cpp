class Solution {
public:
    int solve(string &s,int k){
        int i=0;
        int j=0;
        int n=s.length();
        unordered_map<int,int>mpp;
        int count=0;
        while(j<n){
           mpp[s[j]]++;
           while(mpp.size()>k){
             mpp[s[i]]--;
             if(mpp[s[i]]==0) mpp.erase(s[i]);
             i++;
           }
           count+=(j-i+1);
           j++;
        }
        return count;
    }
    int numberOfSubstrings(string s) {
        return solve(s,3)-solve(s,2);
    }
};