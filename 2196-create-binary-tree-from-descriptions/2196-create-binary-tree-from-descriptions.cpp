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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mpp;
        unordered_set<TreeNode*>st;
        for(auto &each:descriptions){
            TreeNode* p;
            if(mpp.find(each[0])==mpp.end()) {
                p=new TreeNode(each[0]);
                mpp[each[0]]=p;
                st.insert(p);
            }
            else{
                p=mpp[each[0]];
            }
            TreeNode* c;
            if(mpp.find(each[1])==mpp.end()) {
                c=new TreeNode(each[1]);
                mpp[each[1]]=c;
            }

            else{
                c=mpp[each[1]];
                if(st.find(c)!=st.end()) st.erase(c);
            }
            if(each[2]){
                p->left=c;
            }
            else{
                p->right=c;
            }
        }
        return *(st.begin());
    }
};