/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        stringstream ss;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            if(front==NULL){
                ss<<"#,";
            }
            else{
               ss<<front->val<<",";
               q.push(front->left);
               q.push(front->right);
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) 
        return nullptr;
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();
            getline(ss,str,',');
            if(str!="#"){
                front->left=new TreeNode(stoi(str));
                q.push(front->left);
            }
            getline(ss,str,',');
            if(str!="#"){
                front->right=new TreeNode(stoi(str));
                q.push(front->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));