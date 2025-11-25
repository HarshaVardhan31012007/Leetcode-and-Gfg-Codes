// User function Template for C++

class Solution {
  public:
    void heapify(vector<int>&a,int n,int i){
        int lindex=2*i+1;
        int rindex=2*i+2;
        int k=i;
        if(lindex<n&&a[lindex]>a[k])
        k=lindex;
        if(rindex<n&&a[rindex]>a[k])
        k=rindex;
        if(i!=k){
            swap(a[i],a[k]);
            heapify(a,n,k);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        a.insert(a.end(),b.begin(),b.end());
        n=a.size();
        for(int i=n/2-1;i>=0;i--){
            heapify(a,n,i);
        }
        return a;
    }
};