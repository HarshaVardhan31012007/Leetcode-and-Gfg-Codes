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
// class BSTIterator {
// public:
//     vector<int>inorder;
//     int i;
//     void solve(TreeNode* root){
//         if(!root) return;
//         solve(root->left);
//         inorder.push_back(root->val);
//         solve(root->right);
//     }
//     BSTIterator(TreeNode* root) {
//         solve(root);
//         i=-1;
//     }
    
//     int next() {
//         return inorder[++i];
//     }
    
//     bool hasNext() {
//         return i<(int)inorder.size()-1;
//     }
// };




class BSTIterator {
public:
    stack<TreeNode*>st;
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    
    int next() {
        TreeNode* top=st.top();
        st.pop();
        TreeNode* node=top->right;
        while(node){
            st.push(node);
            node=node->left;
        }
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */