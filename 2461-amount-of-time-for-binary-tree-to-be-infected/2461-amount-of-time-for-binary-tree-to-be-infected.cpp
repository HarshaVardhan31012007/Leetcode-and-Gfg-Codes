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
    void createMap(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent,TreeNode* &s,int &target){
        if(!root) return;
        if(root->val==target)
        s=root;
        if(root->left){
            parent[root->left]=root;
            createMap(root->left,parent,s,target);
        }
        if(root->right){
            parent[root->right]=root;
            createMap(root->right,parent,s,target);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* s=NULL;
        unordered_map<TreeNode*,TreeNode*>parent;
        createMap(root,parent,s,start);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        q.push(s);
        visited[s]=true;
        int time=0;
        while(!q.empty()){
             int size=q.size();
             for(int i=0;i<size;i++){
                auto front=q.front();
                q.pop();
                if(front->left&&!visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=true;
                }
                if(front->right&&!visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=true;
                }
                auto parentNode=parent[front];
                if(parentNode&&!visited[parentNode]){
                    q.push(parentNode);
                    visited[parentNode]=true;
                }
             }
             time++;
        }
        return time-1;
    }
};