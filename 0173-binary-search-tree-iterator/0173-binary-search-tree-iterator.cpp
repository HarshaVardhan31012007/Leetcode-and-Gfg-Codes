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
class BSTIterator {
public:
    // vector<int>v;
    //  void create(TreeNode *root){
    //     if(root==NULL){
    //         return;
    //     }
    //     create(root->left);
    //     v.push_back(root->val);
    //     create(root->right);
    //     }

    stack<TreeNode*>st;
    void pushleft(TreeNode *root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
    //    create(root);
    pushleft(root);
    }
    //int i=0;
    int next() {
       // return v[i++];
       TreeNode* top=st.top();
       st.pop();
       if(top->right!=NULL){
        pushleft(top->right); 
       }
       return top->val;
    }
    
    bool hasNext() {
        //return i<v.size();
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */