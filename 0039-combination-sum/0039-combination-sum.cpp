class Solution {
public:
    void solve(vector<int>& candidates, int target,set<vector<int>>&ans,vector<int>&temp){
        if(target==0){
            // you shouldnot sort temp array as it is passed buy reference 
            //whatever element included may change duting backtracking // dont sort
            vector<int>a(temp.begin(),temp.end());
            sort(a.begin(),a.end());
            ans.insert(a);
            return;
        }
        for(auto &candidate:candidates){
            if(candidate<=target){
            temp.push_back(candidate);
            solve(candidates,target-candidate,ans,temp);
            temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>>ans;
        vector<int>temp;
        solve(candidates,target,ans,temp);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
};