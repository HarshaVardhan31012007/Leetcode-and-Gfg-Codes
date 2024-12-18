class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(i>0&&arr[i]==arr[i-1]) continue;
           int j=i+1;
           while(j<n){
           int p=j+1;
           int q=n-1;
           while(p<q){
           
            long long int sum=(long long int)arr[i]+(long long int)arr[j]+(long long int)arr[p]+(long long int)arr[q];
            if(sum<target)
            p++;
            else if(sum>target)
            q--;
            else{
                vector<int>temp={arr[i],arr[j],arr[p],arr[q]};
                ans.push_back(temp);
                p++;
                q--; 
                
             while(p<q&&arr[p]==arr[p-1]) p++;
               }
               
             }
               j++;
        while(j<n&&arr[j]==arr[j-1]) j++;
        }
        }
        return ans;
    }
};