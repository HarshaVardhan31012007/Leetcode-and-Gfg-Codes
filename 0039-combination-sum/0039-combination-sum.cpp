class Solution {
public:
    set<vector<int>>s;
    void solve(vector<int>& candidates,vector<vector<int>>&ans, vector<int>&combin,int target,int i){
         if(target==0){
            if(s.find(combin)==s.end()){
                ans.push_back(combin);
                s.insert(combin);
            }
         }
         if(target<0||i==candidates.size())
         return;
         int num=candidates[i];
         combin.push_back(num);
         //single include
         solve(candidates,ans,combin,target-num,i+1);
         //multiple include
         solve(candidates,ans,combin,target-num,i);
         combin.pop_back();
         //exclude
         solve(candidates,ans,combin,target,i+1);
         
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>combin;
        int i=0;
        solve(candidates,ans,combin,target,i);
        return ans;
    }
};