class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        //if(s.size()==0) return 0;
        int n=g.size();
        int ans=0;
        int i=0;
        for(int j=0;j<s.size()&&i<g.size();j++){
            if(s[j]>=g[i]){
                ans++;
                i++;
            }
        }
        return ans;
    }
};