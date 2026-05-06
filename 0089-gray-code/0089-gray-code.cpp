class Solution {
public:
    void solve(int i,int n,unordered_set<int>&st,vector<int>&ans,vector<int>&temp){
        if(i>n){
           int x=temp.back();
           if((x&(x-1))==0) ans=temp;
           return;
        }
        for(int j=1;j<=n;j++){
            if(st.count(j)) continue;
            int x=(temp.back()^j);
            if((x&(x-1))==0){
                temp.push_back(j);
                st.insert(j);
                solve(i+1,n,st,ans,temp);
                if(!ans.empty()) return;
                temp.pop_back();
                st.erase(j);
            }
        }
    }
    vector<int> grayCode(int n) {
        // vector<int>ans;
        // vector<int>temp;
        // temp.push_back(0);
        // unordered_set<int>st;
        // n=((1<<n)-1);
        // solve(1,n,st,ans,temp);
        // return temp;


        vector<int>ans;
        for(int i=0;i<(1<<n);i++){
            ans.push_back(i^(i>>1));
        }
        return ans;
    }
};