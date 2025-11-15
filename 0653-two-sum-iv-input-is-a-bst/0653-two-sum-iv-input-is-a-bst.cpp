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
    // unordered_map<int,int>mpp;
    // bool solve(TreeNode* root,int k){
    //     if(!root) return 0;
    //     if(mpp.count(k-root->val))
    //     return true;
    //     mpp[root->val]++;
    //     bool  l=solve(root->left,k);
    //     if(l) return true;
    //     bool r=solve(root->right,k);
    //     if(r) return true;
    //     return false;
    // }
    // bool findTarget(TreeNode* root, int k) {
    //     return solve(root,k);
    // }



   
    // void build(TreeNode* root,vector<int>&inorder){
    //     if(!root) return;
    //     build(root->left,inorder);
    //     inorder.push_back(root->val);
    //     build(root->right,inorder);
    // }
    // bool findTarget(TreeNode* root, int k) {
    //     vector<int>inorder;
    //     build(root,inorder);
    //     int i=0;
    //     int j=inorder.size()-1;
    //     while(i<j){
    //         if(inorder[i]+inorder[j]==k) return true;
    //         else if(inorder[i]+inorder[j]<k){
    //             i++;
    //         }
    //         else
    //         j--;
    //     }
    //     return false;
    // }



//     class BSTIterator {
//     public:
//         stack<TreeNode*>st;
//         stack<TreeNode*>revst;
//         void pushLeftNodes(TreeNode* root){
//             while(root){
//                 st.push(root);
//                 root=root->left;
//             }
//         }
//         void pushRightNodes(TreeNode* root){
//             while(root){
//                 revst.push(root);
//                 root=root->right;
//             }
//         }
//         BSTIterator(TreeNode* root) {
//             pushLeftNodes(root);
//             pushRightNodes(root);
//         }
        
//         int next() {
//             TreeNode* top=st.top();
//             st.pop();
//             if(top->right)
//             pushLeftNodes(top->right);
//             return top->val;
//         }
        
//         bool hasNext() {
//             return !st.empty();
//         }

//         int before(){
//             TreeNode* top=revst.top();
//             revst.pop();
//             if(top->left)
//             pushRightNodes(top->left);
//             return top->val;
//         }

//         bool hasBefore() {
//             return !revst.empty();
//         }
//    };

//     bool findTarget(TreeNode* root, int k) {
//        BSTIterator* it=new BSTIterator(root);
//        int a=it->next();
//        int b=it->before();
//        while(a<b){
//            if(a+b==k)
//            return true;
//            else if(a+b<k){
//               a=it->next();
//            }
//            else{
//               b=it->before();
//            }
//        }
//        return false;
//     }



void pushLeftTreeNodes(TreeNode* root,stack<TreeNode*>&s){
        while(root){
            s.push(root);
            root=root->left;
        }
    }
    void pushRightTreeNodes(TreeNode* root,stack<TreeNode*>&s){
        while(root){
            s.push(root);
            root=root->right;
        }
    }
    bool findTarget(TreeNode* root, int k) {
         stack<TreeNode*>st;
         stack<TreeNode*>revst;
         pushLeftTreeNodes(root,st);
         pushRightTreeNodes(root,revst);
         while(!st.empty()&&!revst.empty()&&st.top()->val<revst.top()->val){
             TreeNode* a=st.top();
             TreeNode* b=revst.top();
             if(a->val+b->val==k){
                 st.pop();
                 revst.pop();
                 return true;
                 pushLeftTreeNodes(a->right,st);
                 pushRightTreeNodes(b->left,revst);
             }
             else if(a->val+b->val<k){
                 st.pop();
                 pushLeftTreeNodes(a->right,st);
             }
             else{
                 revst.pop();
                 pushRightTreeNodes(b->left,revst);
             }
         }
        return false;
    }
};