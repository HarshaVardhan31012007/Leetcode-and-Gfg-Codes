class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int s=0;
        int e=n-1;
        int minIndex=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if((arr[mid]-(mid+1))<k){
                minIndex=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        if(minIndex==0&&((arr[0]-1)>=k)) return k;
        k-=(arr[minIndex]-(minIndex+1));
        return arr[minIndex]+k;
    }
};