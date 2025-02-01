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
    struct s{
        vector<int>data;
        int x1;
        int y;
    };
    int find(vector<s>&v,int i,int j){
        for(int k=0;k<v.size();k++){
            if(v[k].x1==i&&v[k].y==j){
                return k;
            }
        }
        return -1;
    }
    void solve(TreeNode *root,vector<s>&v,int l,int x,int &minx,int &maxx,int &lmax){
        if(root==NULL){
            return;
        }
        lmax=max(l,lmax);
        minx=min(minx,x);
        maxx=max(maxx,x);
        int index=find(v,x,l);
        if(index==-1){
        vector<int>p;
        p.push_back(root->val);
        v.push_back({p,x,l});
        }
        else{
           v[index].data.push_back(root->val);
           sort(v[index].data.begin(),v[index].data.end());
        }
        solve(root->left,v,l+1,x-1,minx,maxx,lmax);
        solve(root->right,v,l+1,x+1,minx,maxx,lmax);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<s>v;
        vector<vector<int>>ans;
        int l=0;
        int x=0;
        int minx=INT_MAX;
        int maxx=INT_MIN;
        int lmax=INT_MIN;
        solve(root,v,l,x,minx,maxx,lmax);
        for(int i=minx;i<=maxx;i++){
            vector<int>temp;
            for(int j=0;j<=lmax;j++){
                int index=find(v,i,j);
                if(index!=-1){
                for(int k=0;k<v[index].data.size();k++){
                temp.push_back(v[index].data[k]);
                }
                }
            }
            if(!temp.empty())
            ans.push_back(temp);
        }
        return ans;
    }
};