//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class Info{
    public:
    int data;
    int r;
    int c;
    Info(int x,int y,int z){
        this->data=x;
        this->r=y;
        this->c=z;
    }
};
class compare{
    public:
    bool operator()(Info* a,Info* b){
        return a->data>b->data;
    }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int>ans;
        priority_queue<Info*,vector<Info*>,compare>pq;
        for(int i=0;i<K;i++){
            pq.push(new Info(arr[i][0],i,0));
        }
        while(!pq.empty()){
            Info* top=pq.top();
            pq.pop();
            ans.push_back(top->data);
            if(top->c+1<arr.size()) pq.push(new Info(arr[top->r][top->c+1],top->r,top->c+1));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}






// } Driver Code Ends