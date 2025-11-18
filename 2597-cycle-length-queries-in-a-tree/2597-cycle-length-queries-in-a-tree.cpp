class Solution {
public:
    int find(int k,unordered_map<int,bool>&mpp){
        if(mpp[k]||k==1) return k;
        mpp[k]=1;
        return find(k/2,mpp);
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto &query:queries){
            int a=query[0];int b=query[1];
            unordered_map<int,bool>mpp;
            find(a,mpp);
            int n=find(b,mpp);
            int h1=0,h2=0;
            while(a!=n){
                h1++;
                a=a/2;
            }
            while(b!=n){
                h2++;
                b=b/2;
            }
            ans.push_back(h1+h2+1);
        }
        return ans;
    }
};