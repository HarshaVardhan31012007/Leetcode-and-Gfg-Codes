class Solution {
public:
    bool possible(vector<int>&weights,int days,int mid){
        int n=weights.size();
        int count=1;
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum+weights[i]<=mid){
                sum+=weights[i];
            }
            else{
                count++;
                sum=weights[i];
            }
        }
        return count<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s=*max_element(weights.begin(),weights.end());
        int e=accumulate(weights.begin(),weights.end(),0);
        int ans;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(weights,days,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};