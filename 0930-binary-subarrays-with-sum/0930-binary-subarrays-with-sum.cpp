class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int target) {
        int n=arr.size();
        int j=0;int i=0;
        int sum=0;
        int ans=0;
        while(j<n){
            sum+=arr[j];
            while(sum>target){
                if(arr[i]==1) sum--;
                i++;
            }
            if(sum==target){
                int c1=1,c2=1;int start=i;
                while(i<n&&arr[i]==0){
                    c1++;i++;
                }
                j++;
                while(j<n&&arr[j]==0){
                    c2++;j++;
                }
                if(i<j)
                ans+=c1*c2;
                else{
                    int len=j-start;
                    ans+=(len*(len+1))/2;
                }
            }
            else
            j++;
        }
        return ans;
    }
};