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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=1;
        while(!q.empty()){
          int size=q.size();
          vector<int>lorder(size);
          for(int i=0;i<size;i++){
             TreeNode *front=q.front();
             q.pop();
            int index=(flag==1)?i:size-i-1;
            lorder[index]=front->val;
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
          }
          flag=!flag;
          ans.push_back(lorder);
        }
        return ans;
    }
};