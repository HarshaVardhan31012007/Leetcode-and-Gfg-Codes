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
    TreeNode *bulidTree(vector<int>&in,int i,int j){
         if(i>j)
         return NULL;
        //int mid=ceil((i+j)/2);
        int mid=(i+j+1)/2;
        TreeNode *root=new TreeNode(in[mid]);
        root->left=bulidTree(in,i,mid-1);
        root->right=bulidTree(in,mid+1,j);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return bulidTree(nums,0,nums.size()-1);
    }
};