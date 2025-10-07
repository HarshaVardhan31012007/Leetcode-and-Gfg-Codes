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
    void createPmap(TreeNode* root,map<TreeNode*,TreeNode*>&parent){
        if(root->left){
            parent[root->left]=root;
            createPmap(root->left,parent);
        }
        if(root->right){
            parent[root->right]=root;
            createPmap(root->right,parent);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>parent;
        createPmap(root,parent);
        queue<pair<TreeNode*,int>>q;
        unordered_map<TreeNode*,bool>visited;
        q.push({target,0});
        visited[target]=1;
        vector<int>ans;
        while(!q.empty()&&k>0){
            int size=q.size();
            for(int i=0;i<size;i++){
            auto front=q.front().first;
            int dist=q.front().second;
            q.pop();
            if(front->left&&!visited[front->left]){
                visited[front->left]=true;
                q.push({front->left,dist+1});
            }
            if(front->right&&!visited[front->right]){
                visited[front->right]=true;
                q.push({front->right,dist+1});
            }
            if(parent[front]&&!visited[parent[front]]){
                visited[parent[front]]=true;
                q.push({parent[front],dist+1});
            }
            }
            k--;
        }
           while(!q.empty()){
                ans.push_back(q.front().first->val);
                q.pop();
           }
           return ans;
    }
};