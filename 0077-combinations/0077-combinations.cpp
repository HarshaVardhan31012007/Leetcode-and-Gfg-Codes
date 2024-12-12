class Solution {
public:
    void solve( vector<vector<int>>&ans,vector<int>&output,int i,int n,int k){
        //  if(output.size()==k){
        //     ans.push_back(output);
        //     return;
        //  }
        if(k==0){
            ans.push_back(output);
            return;
        }
         for(int j=i;j<=n;j++){
         output.push_back(j);
         //solve(ans,output,j+1,n,k);
         solve(ans,output,j+1,n,k-1);
         output.pop_back();
         }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>output;
        int i=1;
        solve(ans,output,i,n,k);
        return ans;
    }
};