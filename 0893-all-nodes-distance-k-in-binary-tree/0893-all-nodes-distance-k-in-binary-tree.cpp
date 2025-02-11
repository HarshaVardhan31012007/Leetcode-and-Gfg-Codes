/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void create(TreeNode *root,unordered_map<TreeNode *,TreeNode*>&mpp){
        if(!root) return;
        if(root->left){
        mpp[root->left]=root;
        create(root->left,mpp);
        }
        if(root->right){ 
        mpp[root->right]=root;
        create(root->right,mpp);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode *,TreeNode*>mpp;
        create(root,mpp);
        mpp[root]=NULL;
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        queue<TreeNode*>q;
        q.push(target);
        int l=0;
        while(l!=k){
            int size=q.size();
            l++;
            for(int i=0;i<size;i++){
                auto front=q.front();
                q.pop();
                if(front->left&&visited.find(front->left)==visited.end()){
                    q.push(front->left);
                    visited[front->left]=true;
                }
                if(front->right&&visited.find(front->right)==visited.end()){
                    q.push(front->right);
                    visited[front->right]=true;
                }
                if(mpp[front]&&visited.find(mpp[front])==visited.end()){
                    q.push(mpp[front]);
                    visited[mpp[front]]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};