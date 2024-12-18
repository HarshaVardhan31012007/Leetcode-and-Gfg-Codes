class Solution {
public:
//     void partition(vector<int>& arr, int low, int high) {
//         if(low>=high)
//         return;
//         int pivot=arr[low];
//         int count=0;
//         for(int i=low+1;i<=high;i++){
//             if(arr[i]<=pivot)
//             count++;
//         }
//         int pivotIndex=low+count;
//         swap(arr[low],arr[pivotIndex]);
//         int i=low;
//         int j=high;
//         while(i<pivotIndex&&j>pivotIndex){
//             while(arr[i]<=pivot)
//             i++;
//             while(arr[j]>pivot)
//             j--;
//             if(i<=pivotIndex&&j>=pivotIndex)
//             swap(arr[i++],arr[j--]);
//         }
//         partition(arr,low,pivotIndex-1);
//         partition(arr,pivotIndex+1,high);
//     }
//     void merge(vector<int>&arr,int s,int mid,int e){
//     int i=s;
//     int j=mid+1;
//     while(i<=mid){
//         if(arr[i]>arr[j]){
//          swap(arr[i],arr[j]);
//          partition(arr,j,e);
         
//         }
//         i++;
//     }
    
// }
// void mergeSort(vector<int>&arr,int s,int e){
//     //base case
//     if(s>=e)// here s==e is enough
//     return;
//     int mid=s+(e-s)/2;
//     //left
//     mergeSort(arr,s,mid);
//     //right
//     mergeSort(arr,mid+1,e);
    
//     merge(arr,s,mid,e);
//    }
//     vector<int> sortArray(vector<int>& arr) {
//     int s=0;
//     int n=arr.size();
//     mergeSort(arr,s,n-1);
//     return arr;
//     }

//gap method

    void mergeInplace(vector<int>&arr,int s,int mid,int e){
    int total_len=e-s+1;
    int gap=total_len/2+total_len%2;

    while(gap>0){
        int i=s;
        int j=i+gap;
        while(j<=e){
        if(arr[i]>arr[j]){
         swap(arr[i],arr[j]);
        }
        i++;
        j++;
        }
        gap=gap<=1?0:gap=gap/2+gap%2;
    }
    
}
void mergeSort(vector<int>&arr,int s,int e){
    //base case
    if(s>=e)// here s==e is enough
    return;
    int mid=s+(e-s)/2;
    //left
    mergeSort(arr,s,mid);
    //right
    mergeSort(arr,mid+1,e);
    
    mergeInplace(arr,s,mid,e);
   }
    vector<int> sortArray(vector<int>& arr) {
    int s=0;
    int n=arr.size();
    mergeSort(arr,s,n-1);
    return arr;
    }
};