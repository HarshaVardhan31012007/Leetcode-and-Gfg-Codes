// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     // void buildinorder(TreeNode *root,vector<int>&inorder){
//     //     if(root==NULL){
//     //         return;
//     //     }
//     //     buildinorder(root->left,inorder);
//     //     inorder.push_back(root->val);
//     //     buildinorder(root->right,inorder);
//     // }
//     // bool find(vector<int>&arr,int k){
//     //     int s=0;
//     //     int e=arr.size()-1;
//     //     while(s<e){
//     //         if(arr[s]+arr[e]==k){
//     //             return true;
//     //         }
//     //         else if(arr[s]+arr[e]<k){
//     //             s++;
//     //         }
//     //         else if(arr[s]+arr[e]>k){
//     //             e--;
//     //         }
//     //     }
//     //     return false;
//     // }

//     class BSTIterator {
// public:
//     // vector<int>v;
//     //  void create(TreeNode *root){
//     //     if(root==NULL){
//     //         return;
//     //     }
//     //     create(root->left);
//     //     v.push_back(root->val);
//     //     create(root->right);
//     //     }

//     stack<TreeNode*>st;
//     stack<TreeNode*>revst;
//     void pushleft(TreeNode *root){
//         while(root){
//             st.push(root);
//             root=root->left;
//         }
//     }
//     void pushright(TreeNode *root){
//         while(root){
//             revst.push(root);
//             root=root->right;
//         }
//     }
//     BSTIterator(TreeNode* root) {
//     //    create(root);
//     pushleft(root);
//     pushright(root);
//     }
//     //int i=0;
//     int next() {
//        // return v[i++];
//        TreeNode* top=st.top();
//        st.pop();
//        if(top->right!=NULL){
//         pushleft(top->right); 
//        }
//        return top->val;
//     }
//     int before() {
//        TreeNode* top=revst.top();
//        revst.pop();
//        if(top->left!=NULL){
//         pushleft(top->left); 
//        }
//        return top->val;
//     }
//     bool hasNext() {
//         //return i<v.size();
//         return !st.empty();
//     }
//     bool hasBefore() {
//         return !revst.empty();
//     }
// };
//     bool findTarget(TreeNode* root, int k) {
//         // vector<int>inorder;
//         // buildinorder(root,inorder);
//         // bool ans=find(inorder,k);
//         // return ans;
        
//         if(!root){
//             return false;
//         }
//         BSTIterator it(root);
//         int i=it.next();
//         int j=it.before();
//         while(i<j){
//             int sum=i+j;
//             if(sum==k){
//                 return true;
//             }
//             else if(sum<k){
//               i=it.next();
//             }
//             else{
//               j=it.before();
//             }
//         }
//         return false;
//     }
// };


class BSTIterator {
    stack<TreeNode*>st; // using this stack, I'm doing LNR, inorder traversal.
    stack<TreeNode*>revSt; // reverse inorder traversal
    void pushLeftNodes(TreeNode*root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }

    void pushRightNodes(TreeNode*root){
        while(root){
            revSt.push(root);
            root = root->right;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        pushLeftNodes(root);
        pushRightNodes(root);
    }
    
    int next() {
        auto top = st.top();
        st.pop();

        if(top->right)
            pushLeftNodes(top->right);

        return top->val;
    }

    int before() {
        auto top = revSt.top();
        revSt.pop();

        if(top->left)
            pushRightNodes(top->left);

        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    bool hasBefore() {
        return !revSt.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator it(root);

        int i = it.next(); // smalled, L -> R
        int j = it.before(); // largest, R -> L

        while(i < j){
            int sum = i + j;
            if(sum == k) return true;
            else if(sum < k)
                i = it.next(); // start++
            else
                j = it.before(); // end--
        }
        return false;
    }
};