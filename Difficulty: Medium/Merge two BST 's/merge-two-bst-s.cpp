//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
     void buildinorder(Node *root,vector<int>&inorder1){
        if(root==NULL){
            return;
        }
        buildinorder(root->left,inorder1);
        inorder1.push_back(root->data);
        buildinorder(root->right,inorder1);
    }
    vector<int>merge(vector<int>&a,vector<int>&b){
        vector<int>ans(a.size()+b.size(),0);
        int k=0;
        int i=0;
        int j=0;
        while(i<a.size()&&j<b.size()){
            if(a[i]<b[j]){
                ans[k++]=a[i++];
            }
            else{
                ans[k++]=b[j++];
            }
        }
        while(i<a.size()){
                ans[k++]=a[i++];
        }
        while(j<b.size()){
                ans[k++]=b[j++];
        }
        return ans;
    }
    Node *bulidTree(vector<int>&in,int i,int j){
         if(i>j)
         return NULL;
        int mid=(i+j)/2;
        Node *root=new Node(in[mid]);
        root->left=bulidTree(in,i,mid-1);
        root->right=bulidTree(in,mid+1,j);
        return root;
    }
    vector<int> merge(Node *root1, Node *root2) {
        vector<int>a;
        vector<int>b;
        buildinorder(root1,a);
        buildinorder(root2,b);
        vector<int>ans=merge(a,b);
        bulidTree(ans,0,ans.size()-1);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends