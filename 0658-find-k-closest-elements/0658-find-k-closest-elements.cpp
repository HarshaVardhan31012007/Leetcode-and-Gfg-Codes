class Solution {
public:
    // int bs(vector<int>&arr,int s,int e,int t){
    //     int ans=-1;
    //     while(s<=e){
    //         int mid=s+(e-s)/2;
    //         if(arr[mid]<t)
    //         s=mid+1;
    //         if(arr[mid]>=t){
    //             ans=mid;
    //             e=mid-1;
    //         }
    //     }
    //     return ans;
    // }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // priority_queue<pair<int,int>>pq;
        // for(int i=0;i<arr.size();i++){
        //     pq.push({abs(arr[i]-x),arr[i]});
        //     if(pq.size()>k)
        //     pq.pop();
        // }
        // vector<int>ans;
        // while(!pq.empty()){
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // sort(ans.begin(),ans.end());
        // return ans;

        

        int s=0;
        int e=arr.size()-1;
        vector<int>ans;
        while(e-s>=k){
            if(x-arr[s]>arr[e]-x)
            s++;
            else
            e--;
        }
        for(int i=s;i<=e;i++){
           ans.push_back(arr[i]);
        }
        return ans;




        // int idx=bs(arr,0,arr.size()-1,x);
        // int i=idx-1;int j=idx;
        // vector<int>ans;
        // while(j-i-1<k){
        //     if(i<0||abs(arr[i]-x)>abs(arr[j]-x)){
        //         ans.push_back(arr[j++]);
        //     }
        //     else if(j>=arr.size()||abs(arr[i]-x)<=abs(arr[j]-x)){
        //         ans.insert(ans.begin(),arr[i--]);
        //     }
        // }
        // return ans;
    }
};