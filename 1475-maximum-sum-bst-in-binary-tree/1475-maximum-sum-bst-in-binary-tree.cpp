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
      class info{
        public:
        int minval;
        int maxval;
        bool isbst;
        int sum;
      };


//     int sum(TreeNode *root){
//         if(root==NULL){
//             return 0;
//         }
//         int lans=sum(root->left);
//         int rans=sum(root->right);
//         return lans+rans+root->val;
//     }
//     //method 3
//     int getMin(TreeNode *root){
//       if(root==NULL){
//         return INT_MAX;
//     }
//     while(root->left!=NULL){
//         root=root->left;
//     }
//     return root->val;
// }
// int getMax(TreeNode *root){
//     if(root==NULL){
//         return INT_MIN;
//     }
//     while(root->right!=NULL){
//         root=root->right;
//     }
//     return root->val;
// }
    //method 1 and method 2
    // bool check(TreeNode *root,int mini=INT_MIN,int maxi=INT_MAX){
    //     if(root==NULL){
    //         return true;
    //     }
    //     bool currans=root->val>mini&&root->val<maxi;
    //     if(currans==false){
    //         return false;
    //     }
    //     bool leftans=check(root->left,mini,root->val);
    //     bool rightans=check(root->right,root->val,maxi);
    //     return currans&&rightans&&leftans;
    // }
    //method 1
    // void traverse(TreeNode *root,vector<TreeNode*>&v){
    //    if(root==NULL){
    //     return;
    //    }
    //    bool ans=check(root);
    //    if(ans==1){
    //     v.push_back(root);
    //    }
    //    traverse(root->left,v);
    //    traverse(root->right,v);
    // }
    //method 2
    //  void traverse(TreeNode *root,int &s){
    //    if(root==NULL){
    //     return;
    //    }
    //    bool ans=check(root);
    //    if(ans==1){
    //     s=max(s,sum(root));
    //    }
    //    traverse(root->left,s);
    //    traverse(root->right,s);
    // }
    //method 3
    //   void traverse(TreeNode *root,int &s){
    //    if(root==NULL){
    //     return;
    //    }
    //    bool ans=root->val>getMax(root->left)&&root->val<getMin(root->right);
    //    if(ans==1){
    //     s=max(s,sum(root));
    //    }
    //    traverse(root->left,s);
    //    traverse(root->right,s);
    // }


    info solve(TreeNode *root,int &s){
        if(root==NULL){
            info temp;
            temp.minval=INT_MAX;
            temp.maxval=INT_MIN;
            temp.sum=0;
            temp.isbst=true;
            s=max(s,temp.sum);
            return temp;
        }
        //LRN
        info lans=solve(root->left,s);
        info rans=solve(root->right,s);
        info curr;
        curr.minval=min(root->val,min(lans.minval,rans.minval));
        curr.maxval=max(root->val,max(lans.maxval,rans.maxval));
        curr.sum=root->val+lans.sum+rans.sum;
        curr.isbst=root->val>lans.maxval&&root->val<rans.minval&&lans.isbst&&rans.isbst;
        if(curr.isbst){
            s=max(s,curr.sum);
        }
        return curr;
    }
    int maxSumBST(TreeNode* root) {
    //method 1
    //    vector<TreeNode*>v;
    //    v.push_back(NULL);
    //    traverse(root,v);
    //    int maxAns=INT_MIN;
    //    for(int i=0;i<v.size();i++){
    //      int curr=sum(v[i]);
    //      maxAns=max(curr,maxAns);
    //    }
    //    return maxAns;
    // }
    //method 2
    // int s=0;
    // traverse(root,s);
    // return s;



     int s=0;
     solve(root,s);
     return s;
    }
};