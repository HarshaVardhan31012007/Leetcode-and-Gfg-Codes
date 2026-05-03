class Solution {
public:
    bool check(unordered_map<char,int>&mpp){
        for(auto &each:mpp){
            if(each.second>0) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        //if(s.length()<t.length()) return "";
        unordered_map<char,int>mpp;

        for(auto &each:t){
            mpp[each]++;
        }

        int i=0;
        int j=0;
        int n=s.length();
        int start=-1;int len=INT_MAX;
        while(j<n){
            if(mpp.count(s[j]))
            mpp[s[j]]--;
            while(check(mpp)){
                if((j-i+1)<len){
                    start=i;
                    len=(j-i+1);
                }
                if(mpp.count(s[i])) mpp[s[i]]++;
                i++;
            }
            j++;
        }
        if(start==-1) return "";
        return s.substr(start,len);
    }
};