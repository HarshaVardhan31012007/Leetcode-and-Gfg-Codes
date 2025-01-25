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
    stack<TreeNode*>revst;
    void pushleft(TreeNode *root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }
    void pushright(TreeNode *root){
        while(root){
            revst.push(root);
            root=root->right;
        }
    }
    BSTIterator(TreeNode* root) {
    //    create(root);
    pushleft(root);
    pushright(root);
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
    int before() {
       TreeNode* top=revst.top();
       st.pop();
       if(top->left!=NULL){
        pushright(top->left); 
       }
       return top->val;
    }
    bool hasNext() {
        //return i<v.size();
        return !st.empty();
    }
    bool hasBefore() {
        return !revst.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */