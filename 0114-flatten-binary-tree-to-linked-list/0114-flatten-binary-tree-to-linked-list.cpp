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
    // void solve(TreeNode* root,vector<int>&node){
    //      if(!root) return;
    //      node.push_back(root->val);
    //      solve(root->left,node);
    //      solve(root->right,node);
    // }
    // void flatten(TreeNode* root) {
    //     vector<int>node;
    //     solve(root,node);
    //     if(node.empty())
    //     return;
    //     root->val=node[0];// ans checking wiill be done by root address only not local address
    //     root->left=NULL;
    //     TreeNode* it=root;
    //     for(int i=1;i<node.size();i++){
    //         it->right=new TreeNode(node[i]);
    //         it=it->right;
    //     }
    // }


    // void solve(TreeNode* root,vector<int>&node){
    //      if(!root) return;
    //      node.push_back(root->val);
    //      solve(root->left,node);
    //      solve(root->right,node);
    // }
    // void build(TreeNode *&root,vector<int>&node,int &i){
    //     if(i>=node.size()) return;
    //     root=new TreeNode(node[i++]);
    //     build(root->right,node,i);
    // }
    // void flatten(TreeNode* root) {
    //     vector<int>node;
    //     solve(root,node);
    //     if(node.empty())
    //     return;
    //     root->val=node[0];
    //     root->left=NULL;
    //     int i=1;
    //     build(root->right,node,i);
    // }


    //  void solve(TreeNode* root,vector<TreeNode*>&node){
    //      if(!root) return;
    //      node.push_back(root);
    //      solve(root->left,node);
    //      solve(root->right,node);
    // }
    // void flatten(TreeNode* root) {
    //     vector<TreeNode*>node;
    //     solve(root,node);
    //     if(node.empty())
    //     return;
    //     for(int i=0;i<node.size()-1;i++){
    //          node[i]->left=NULL;
    //          node[i]->right=node[i+1];
    //     }
    //     node[node.size()-1]=NULL;
    // }

    TreeNode* solve1(TreeNode* node){
       while(node->right)
       node=node->right;
       return node;
    }
    void solve(TreeNode* root,TreeNode* p){
         if(!root) return;
         solve(root->left,root);
         solve(root->right,root);
         if(root->left){
            TreeNode* eleft=solve1(root->left);
            eleft->right=root->right;
            root->right=root->left;
            root->left=NULL;
         }
    }
    void flatten(TreeNode* root) {
        solve(root,NULL);
    }
};