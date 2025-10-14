// class Solution {
// public:
//     void solve(vector<int>& candidates, int target,set<vector<int>>&ans,vector<int>&temp){
//         if(target==0){
//             // you shouldnot sort temp array as it is passed buy reference 
//             //whatever element included may change duting backtracking // dont sort
//             vector<int>a(temp.begin(),temp.end());
//             sort(a.begin(),a.end());
//             ans.insert(a);
//             return;
//         }
//         for(auto &candidate:candidates){
//             if(candidate<=target){
//             temp.push_back(candidate);
//             solve(candidates,target-candidate,ans,temp);
//             temp.pop_back();
//             }
//         }
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         set<vector<int>>ans;
//         vector<int>temp;
//         solve(candidates,target,ans,temp);
//         return vector<vector<int>>(ans.begin(),ans.end());
//     }
// };


class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&temp,int i){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=candidates.size()||target<0) return;
        for(int j=i;j<candidates.size();j++){
            temp.push_back(candidates[j]);
            solve(candidates,target-candidates[j],ans,temp,j);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(candidates,target,ans,temp,0);
        return ans;
    }
};



// class Solution {
// public:
//     void solve(vector<int>& candidates, int target,set<vector<int>>&ans,vector<int>&temp,int i){
//         if(target==0){
//               ans.insert(temp);
//               return;
//         } 
//         if(i==candidates.size()||target<0) return;
//         temp.push_back(candidates[i]);
//         solve(candidates,target-candidates[i],ans,temp,i+1);
//         solve(candidates,target-candidates[i],ans,temp,i);
//         temp.pop_back();
//         solve(candidates,target,ans,temp,i+1);
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         set<vector<int>>ans;
//         vector<int>temp;
//         solve(candidates,target,ans,temp,0);
//         return vector<vector<int>>(ans.begin(),ans.end());
//     }
// };


// class Solution {
// public:
    // void solve(vector<int>& candidates, int target,vector<vector<int>>&ans,vector<int>&temp,int i){
    //     if(target==0){
    //           ans.push_back(temp);
    //           return;
    //     } 
    //     if(i==candidates.size()||target<0) return;
    //     temp.push_back(candidates[i]);
    //     solve(candidates,target-candidates[i],ans,temp,i);
    //     temp.pop_back();
    //     solve(candidates,target,ans,temp,i+1);
    // }
    // vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    //     vector<vector<int>>ans;
    //     vector<int>temp;
    //     solve(candidates,target,ans,temp,0);
    //     return ans;
    // }
//};