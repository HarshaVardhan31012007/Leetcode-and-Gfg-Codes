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

    // Encodes a tree to a single string.
    
    // string preorder(TreeNode* root){
    //     if(!root) return "N";
    //     string l=preorder(root->left);
    //     string r=preorder(root->right);
    //     string curr=to_string(root->val)+" "+l+" "+r;
    //     return curr;
    // }

    // string serialize(TreeNode* root) {
    //     return preorder(root);
    // }

    // // Decodes your encoded data to tree.
    // TreeNode* create(string data,int &i){
    //     if(data[i]=='N') {
    //         i=i+2;
    //         return nullptr;
    //     }
    //     int n=0;
    //     int sign=1;
    //     if(data[i]=='-'){
    //         i++;
    //         sign=-1;
    //     }
    //     while(i<data.length()&&isdigit(data[i])){
    //         n=n*10+(data[i]-'0');
    //         i++;
    //     }
    //     i++;
    //     TreeNode* root=new TreeNode(n*sign);
    //     root->left=create(data,i);
    //     root->right=create(data,i);
    //     return root;
    // }
    // TreeNode* deserialize(string data) {
    //    int i=0;
    //    return create(data,i);
    // }




    string serialize(TreeNode* root) {
         queue<TreeNode*>q;
         q.push(root);
         string s="";
         while(!q.empty()){
            auto front=q.front();
            q.pop();
            if(front==NULL) s+="#,";
            else{
                s+=to_string(front->val)+',';
                q.push(front->left);
                q.push(front->right);
            }
         }
         return s;
    }
    void change(TreeNode* &curr,int &i,string &data){
        if(data[i]=='#'){
            curr=NULL;
            i=i+2;
            return;
        }
        int n=0;
        int sign=1;
        if(data[i]=='-'){
            sign=-1;
            i++;
        }
        while(i<data.length()&&isdigit(data[i])){
           n=n*10+(data[i]-'0');
           i++;
        }
        i++;//to skip ,
        curr=new TreeNode(n*sign);
    }
    TreeNode* deserialize(string data) {
        //if(data=="#,") return NULL;
        TreeNode* root=NULL;
        int i=0;
        change(root,i,data);
        queue<TreeNode*>q;
        if(root)
        q.push(root);
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            change(front->left,i,data);
            change(front->right,i,data);
            if(front->left)
            q.push(front->left);
            if(front->right)
            q.push(front->right);
        }
        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));