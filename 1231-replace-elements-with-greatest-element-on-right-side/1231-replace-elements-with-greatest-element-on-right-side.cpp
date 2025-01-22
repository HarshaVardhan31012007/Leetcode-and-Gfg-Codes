class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxi=INT_MIN;
        int n=arr.size();
        for(int i=n-1;i>=0;i--){
           int t=arr[i];
           if(maxi==INT_MIN)
           arr[i]=-1; 
           else
           arr[i]=maxi;
           maxi=max(maxi,t);
        }
        return arr;
    }
};