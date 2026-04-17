/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // map<pair<int,int>,vector<TreeNode*>>mpp;
    // vector<TreeNode*>solve(int s,int e){
    //     if(s>e) return {NULL};
    //     if(s==e) return {new TreeNode(0)};
    //     if(mpp.count({s,e})) return mpp[{s,e}];
    //     vector<TreeNode*>ans;
    //     for(int i=s+1;i<e;i++){
    //         vector<TreeNode*>left=solve(s,i-1);
    //         vector<TreeNode*>right=solve(i+1,e);
    //         for(auto &each:left){
    //             for(auto &each1:right){
    //                 TreeNode* root=new TreeNode(0);
    //                 root->left=each;
    //                 root->right=each1;
    //                 ans.push_back(root);
    //             }
    //         }
    //     }
    //     return mpp[{s,e}]=ans;
    // }
    // vector<TreeNode*> allPossibleFBT(int n) {
    //     return solve(1,n);
    // }




    map<int,vector<TreeNode*>>mpp;
    vector<TreeNode*>solve(int n){
        if(n==0) return {NULL};
        if(n==1) return {new TreeNode(0)};
        if(mpp.count(n)) return mpp[n];
        vector<TreeNode*>ans;
        for(int i=1;i<n-1;i++){
            vector<TreeNode*>left=solve(i);
            vector<TreeNode*>right=solve(n-i-1);
            for(auto &each:left){
                for(auto &each1:right){
                    TreeNode* root=new TreeNode(0);
                    root->left=each;
                    root->right=each1;
                    ans.push_back(root);
                }
            }
        }
        return mpp[n]=ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};