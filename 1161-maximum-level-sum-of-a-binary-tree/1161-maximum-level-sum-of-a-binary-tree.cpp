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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        int sum=INT_MIN;int level=1;int ans=0;
        if(root)
        q.push(root);
        while(!q.empty()){
            int size=q.size();int csum=0;
            for(int i=0;i<size;i++){
                auto front=q.front();
                q.pop();
                csum+=front->val;
                if(front->left)
                q.push(front->left);
                if(front->right)
                q.push(front->right);
            }
            if(csum>sum){
                sum=csum;
                ans=level;
            }
            level++;
        }
        return ans;
    }
};