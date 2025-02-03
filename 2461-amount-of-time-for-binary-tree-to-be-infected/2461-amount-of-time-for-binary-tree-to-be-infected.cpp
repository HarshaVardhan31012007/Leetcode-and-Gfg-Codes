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
    void solve(TreeNode *root,int k,TreeNode *&target,unordered_map<TreeNode*,TreeNode*>&mpp){
        if(root==NULL){
            return;
        }
        if(root->val==k){
           target=root;
        }
        if(root->left)
        mpp[root->left]=root;
        if(root->right)
        mpp[root->right]=root;
        solve(root->left,k,target,mpp);
        solve(root->right,k,target,mpp);
    }
    int solve1(TreeNode *curr,unordered_map<TreeNode*,TreeNode*>&mpp){
        unordered_map<TreeNode*,bool>visited;
        int T=0;
        queue<TreeNode*>q;
        visited[curr]=1;
        q.push(curr);
        while(!q.empty()){
          int size=q.size();
          bool a=0;
          for(int i=0;i<size;i++){
          TreeNode *front=q.front();
          q.pop();
          if(front->left&&!visited[front->left]){
               q.push(front->left);
               visited[front->left]=1;
               a=1;
          }
          if(front->right&&!visited[front->right]){
               q.push(front->right);
               visited[front->right]=1;
               a=1;
          }
          if(mpp[front]&&!visited[mpp[front]]){
            visited[mpp[front]]=1;
            q.push(mpp[front]);
            a=1;
          }
          }
           if(a){
             T++;
           }
        }
        return T;
    }
    int amountOfTime(TreeNode* root, int start) {
        //find target
        //mapping for parent element
        //you can use any traversal
        //level order or preorder or inorder or postorder
        TreeNode *target=NULL;
        unordered_map<TreeNode*,TreeNode*>mpp;
        solve(root,start,target,mpp);
        int ans=solve1(target,mpp);
        return ans;
    }
};