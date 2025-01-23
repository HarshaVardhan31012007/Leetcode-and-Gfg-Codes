//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    class Node
    {
       public:
       int data;
       Node *left;
       Node *right;
       Node(int val):data(val),left(0),right(0){};
    };
    Node *build(Node *root,int &succ,int val){
        if(!root)
        return new Node(val);
        if(val>=root->data){
            root->right=build(root->right,succ,val);
        }
        else{
            succ=root->data;
            root->left=build(root->left,succ,val);
        }
        return root;
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int>ans(arr.size(),-1);
        Node *root=NULL;
        for(int i=arr.size()-1;i>=0;i--){
            int succ=-1;
            root=build(root,succ,arr[i]);
            ans[i]=succ;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends