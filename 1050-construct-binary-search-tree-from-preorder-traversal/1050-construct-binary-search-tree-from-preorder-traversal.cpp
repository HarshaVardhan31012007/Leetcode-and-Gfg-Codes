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
    // TreeNode* build(vector<int>&preorder,int s,int e){
    //     if(s>e) return NULL;
    //     TreeNode* root=new TreeNode(preorder[s]);
    //     int j=s+1;
    //     while(j<=e){
    //         if(preorder[j]>root->val){
    //             break;
    //         }
    //         j++;
    //     }
    //     root->left=build(preorder,s+1,j-1);
    //     root->right=build(preorder,j,e);
    //     return root;
    // }
    // TreeNode* bstFromPreorder(vector<int>& preorder) {
    //     return build(preorder,0,preorder.size()-1);
    // }



    TreeNode* build(vector<int>&preorder,int &i,int mini,int maxi){
         if(i>=preorder.size()) return NULL;
         if(preorder[i]>mini&&preorder[i]<maxi){
            TreeNode* root=new TreeNode(preorder[i++]);
            root->left=build(preorder,i,mini,root->val);
            root->right=build(preorder,i,root->val,maxi);
            return root;
         }
         return NULL;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,0,1001);
    }
};