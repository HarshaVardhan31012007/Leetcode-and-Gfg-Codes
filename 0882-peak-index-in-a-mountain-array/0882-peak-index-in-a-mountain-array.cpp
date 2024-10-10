class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0;
        int n=arr.size();
        int e=n-1;
        while(s<=e){
        int mid=s+(e-s)/2;
        if(mid!=0&&mid!=n-1&&arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])
        return mid;
        if(mid!=0&&mid!=n-1&&arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1])
        s=mid+1;
        if(mid!=0&&mid!=n-1&&arr[mid]<arr[mid-1]&&arr[mid]>arr[mid+1])
        e=mid-1;
        if(mid==0)
        s++;
        mid=s+(e-s)/2;
        }
    return -1;
    }
};