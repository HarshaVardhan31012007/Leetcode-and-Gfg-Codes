class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        // sort(arr.begin(),arr.end());
        int n=arr.size();
        // for(int i=0;i<n;i++){
        //         if(arr[i]==arr[i+1])
        //         return arr[i];
            
        // }
        // return -1;

        //visiting method
    //    int ans=-1;
    //    for(int i=0;i<n;i++){
    //     int index=abs(arr[i]);
    //     if(arr[index]<0){
    //         ans=index;
    //         break;
    //     }
    //     arr[index]*=-1;
    //    }
     //  return ans;


     //positioning method
     while(arr[0]!=arr[arr[0]]){
        swap(arr[0],arr[arr[0]]);
     }
     return arr[0];
    }
};