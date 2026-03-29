class Solution {
public:
    // int findContentChildren(vector<int>& g, vector<int>& s) {
    //     multiset<int>st(s.begin(),s.end());
    //     int ans=0;
    //     for(auto &each:g){
    //         auto it=st.lower_bound(each);
    //         if(it!=st.end()){
    //            ans++;
    //            st.erase(it);
    //         }
    //     }
    //     return ans;
    // }
    

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int i=0,j=0;int ans=0;
        while(j<s.size()&&i<g.size()){
            if(g[i]<=s[j]){
               ans++;
               i++;
            }
            j++;
        }
        return ans;
    }
};