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
        //MLE
        // deque<TreeNode*>q;
        // q.push_back(root);
        // int width=1;
        // while(!q.empty()){
        //     int size=q.size();
        //     for(int i=0;i<size;i++){
        //         auto front=q.front();
        //         q.pop_front();
        //         if(front==NULL){
        //             q.push_back(NULL);
        //             q.push_back(NULL);
        //         }
        //         else{
        //             q.push_back(front->left);
        //             q.push_back(front->right);
        //         }
        //     }
        //     while(!q.empty()&&q.back()==NULL){
        //         q.pop_back();
        //     }
        //     while(!q.empty()&&q.front()==NULL){
        //         q.pop_front();
        //     }
        //     if(q.front()!=NULL&&q.back()!=NULL)
        //     width=max(width,(int)q.size());
        // }
        // return width;



        queue<pair<TreeNode*,unsigned long long>>q;
        unsigned long long int width=1;
        q.push({root,1});
        while(!q.empty()){
            unsigned long long int size=q.size();
            for(unsigned long long int i=0;i<size;i++){
            auto front=q.front().first;
            unsigned long long idx=q.front().second;
            q.pop();
            if(front->left)
            q.push({front->left,2*idx});
            if(front->right)
            q.push({front->right,2*idx+1});
            }
            if(q.size()>=2){
                width=max(width,q.back().second-q.front().second+1);
            }
        }
        return width;
    }
};