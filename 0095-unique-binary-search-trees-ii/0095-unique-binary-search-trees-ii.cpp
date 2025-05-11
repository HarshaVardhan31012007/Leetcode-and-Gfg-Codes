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
    vector<TreeNode*>solve(int s,int e){
        if(s>e) return {0};
        if(s==e) return {new TreeNode(s)};
        vector<TreeNode*>ans;
        for(int i=s;i<=e;i++){
            vector<TreeNode*>l=solve(s,i-1);
            vector<TreeNode*>r=solve(i+1,e);
            for(int k=0;k<l.size();k++){
                for(int j=0;j<r.size();j++){
                    TreeNode *root=new TreeNode(i);
                    root->left=l[k];
                    root->right=r[j];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};