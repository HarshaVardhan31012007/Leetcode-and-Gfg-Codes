class Solution {
  public:
    // Function to sort an array using quick sort algorithm.
    // void quickSort(vector<int>& arr, int low, int high) {
    //     // code here
    //     //base case
    //     if(low>=high)
    //     return;
    //     int i=low-1;
    //     int j=low;
    //     int pivot=high;
    //     while(j<pivot){
    //         if(arr[j]<arr[pivot]){
    //             i++;
    //             swap(arr[i],arr[j]);
    //         }
    //         j++;
    //     }
    //     i++;
    //     swap(arr[i],arr[pivot]);
    //     quickSort(arr,low,i-1);
    //     quickSort(arr,i+1,high);
    // }
    
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        //base case
        if(low>=high)
        return;
       int p=partition(arr,low,high);
        
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }

  public:
    // Function that takes last element as pivot, places the pivot element at
    // its correct position in sorted array, and places all smaller elements
    // to left of pivot and all greater elements to right of pivot.
    int partition(vector<int>& arr, int low, int high) {
        // code here
        int i=high+1;
        int j=high;
        int pivot=low;
        while(j>pivot){
            if(arr[j]>arr[pivot]){
                i--;
                swap(arr[i],arr[j]);
            }
            j--;
        }
        i--;
        swap(arr[i],arr[pivot]);
        return i;
    }
    //method 2 for partition
    // int partition(vector<int>& arr, int low, int high) {
    //     // code here
    //     int pivot=arr[low];
    //     int count=0;
    //     for(int i=low+1;i<=high;i++){
    //         if(arr[i]<=pivot)
    //         count++;
    //     }
    //     int pivotIndex=low+count;
    //     swap(arr[low],arr[pivotIndex]);
    //     int i=low;
    //     int j=high;
    //     while(i<pivotIndex&&j>pivotIndex){
    //         while(arr[i]<=pivot)
    //         i++;
    //         while(arr[j]>pivot)
    //         j--;
    //         if(i<pivotIndex&&j>pivotIndex)
    //         swap(arr[i++],arr[j--]);
    //     }
    //     return pivotIndex;
    // }
};