class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        multiset<int>st(s.begin(),s.end());
        // unordered_map<int,int>freq;
        // for(auto &each:s)
        // freq[each]++;
        int ans=0;
        for(auto &each:g){
            auto it=st.lower_bound(each);
            if(it!=st.end()){
               ans++;
               st.erase(it);
            }
        }
        return ans;
    }
};