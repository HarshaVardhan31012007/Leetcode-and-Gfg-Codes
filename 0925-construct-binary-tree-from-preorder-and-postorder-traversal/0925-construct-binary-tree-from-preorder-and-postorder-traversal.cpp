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
    int find(vector<int>&v,int d,int s,int e){
        for(int i=s;i<=e;i++){
            if(v[i]==d)
            return i;
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& postorder,int &i,int s,int e){
        if(s>e) return NULL;
        TreeNode* root=new TreeNode(preorder[i++]);
        if(s==e) return root;
        int idx=find(postorder,preorder[i],s,e);
        root->left=build(preorder,postorder,i,s,idx);
        root->right=build(preorder,postorder,i,idx+1,e-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
         int i=0;
         return build(preorder,postorder,i,0,preorder.size()-1);
    }
};