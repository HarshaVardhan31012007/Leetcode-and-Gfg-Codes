// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Node{
//     public:
//     int mini;
//     int maxi;
//     int sum;
//     bool isBST;
//     Node(){
//         mini=INT_MAX;maxi=INT_MIN;
//         sum=0;isBST=true;
//     }
// };
// class Solution {
// public:
//     int ans;
//     //edgec ase all avlues are negative then null is also bst that means maxsum is 0
//     Node* getMaxSumBST(TreeNode* root){
//         if(!root) return new Node();
//         Node* left=getMaxSumBST(root->left);
//         Node* right=getMaxSumBST(root->right);
//         Node* curr=new Node();
//         if(left->isBST&&right->isBST&&root->val>left->maxi&&root->val<right->mini){
//             curr->isBST=true;
//             curr->mini=min(root->val,left->mini);
//             curr->maxi=max(root->val,right->maxi);
//             curr->sum=root->val+left->sum+right->sum;
//             ans=max(ans,curr->sum);
//             return curr;
//         }
//         curr->isBST=false;
//         return curr;
//     }
//     int maxSumBST(TreeNode* root) {
//         ans=0;
//         getMaxSumBST(root);
//         return ans;
//     }
// };


struct Node{
   int mini;
   int maxi;
   int sum;  
};
class Solution{
	public:
        int ans;
        Node solve(TreeNode* root){
            if(!root) return {INT_MAX,INT_MIN,0};
            Node left=solve(root->left);
            Node right=solve(root->right);
            if(left.maxi<root->val&&root->val<right.mini){
                ans=max(ans,left.sum+right.sum+root->val);
                return {min(root->val,left.mini),max(root->val,right.maxi),left.sum+right.sum+root->val};
            }
            return {INT_MIN,INT_MAX,max(left.sum,right.sum)};
        }
		int maxSumBST(TreeNode* root){
            ans=0;
			solve(root);
            return ans;
		}
};