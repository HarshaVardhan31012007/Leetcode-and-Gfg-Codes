class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        int n=s.length();
        for(int i=0;i<=n-k;i++){
            string temp=s.substr(i,k);
            st.insert(temp);
        }
        return ((int)st.size())==(1<<k);
    }
};