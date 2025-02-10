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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,1});
        unsigned long long maxi=0;
        while(!q.empty()){
             int size=q.size();
             maxi=max(maxi,q.back().second-q.front().second+1);
             for(int i=0;i<size;i++){
                 auto front=q.front();
                 q.pop();
                 if(front.first->left)
                 q.push({front.first->left,2*front.second});
                 if(front.first->right)
                 q.push({front.first->right,2*front.second+1});
             }
        }
        return maxi;
    }
};