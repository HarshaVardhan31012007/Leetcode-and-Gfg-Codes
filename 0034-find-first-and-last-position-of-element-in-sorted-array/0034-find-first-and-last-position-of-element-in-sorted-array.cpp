class Solution {
public:
void binary_firstoccurence(vector<int>arr,int n,int target,int &ansIndex){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==target){
            ansIndex=mid;
            e=mid-1;
        }
        if(arr[mid]<target)
        s=mid+1;
        if(arr[mid]>target)
        e=mid-1;

        mid=s+(e-s)/2;

    }
}
void binary_lastoccurence(vector<int>arr,int n,int target,int &ansIndex){
    int s=0;
    int e=n-1;
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==target){
            ansIndex=mid;
            s=mid+1;
        }
        if(arr[mid]<target)
        s=mid+1;
        if(arr[mid]>target)
        e=mid-1;

        mid=s+(e-s)/2;

    }
}
    vector<int> searchRange(vector<int>& arr, int target) {
        int n=arr.size();
        int ansIndex1=-1;
        int ansIndex2=-1;
        binary_firstoccurence(arr,n,target,ansIndex1);
        binary_lastoccurence(arr,n,target,ansIndex2);
        vector<int>temp(2);
        temp[0]=ansIndex1;
        temp[1]=ansIndex2;
        return temp;
    }
};