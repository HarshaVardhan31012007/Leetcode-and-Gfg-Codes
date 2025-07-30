class Solution {
public:
    void solve(int n,int k,int i,vector<vector<int>>&ans,vector<int>&temp){
        if(k==0) {
            ans.push_back(temp);
            return;
        }
        for(int j=i;j<=n;j++){
            temp.push_back(j);
            solve(n,k-1,j+1,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(n,k,1,ans,temp);
        return ans;
    }
};