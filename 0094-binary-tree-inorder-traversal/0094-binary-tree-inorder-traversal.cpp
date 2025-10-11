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
    vector<int> inorderTraversal(TreeNode* root) {
          TreeNode* curr=root;
          vector<int>ans;
          while(curr){
                if(curr->left==NULL){// no predecessor
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
                else{//predecessor exist
                     TreeNode* pred=curr->left;
                     while(pred->right!=curr&&pred->right)
                     pred=pred->right;
                     //if link is not created
                     if(pred->right==NULL){
                         pred->right=curr;
                         curr=curr->left;
                     }
                     else{// link already there
                         pred->right=NULL;
                         ans.push_back(curr->val);
                         curr=curr->right;
                     }
                }
          }
          return ans;
    }
};