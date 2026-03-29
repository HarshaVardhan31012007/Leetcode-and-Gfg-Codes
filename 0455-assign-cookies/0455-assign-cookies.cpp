class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort(g.begin(),g.end());
        // sort(s.begin(),s.end());
        // int n=g.size();
        // int ans=0;
        // int i=0;
        // for(int j=0;j<s.size()&&i<g.size();j++){
        //     if(s[j]>=g[i]){
        //         ans++;
        //         i++;
        //     }
        // }
        // return ans;


        multiset<int>st(s.begin(),s.end());
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