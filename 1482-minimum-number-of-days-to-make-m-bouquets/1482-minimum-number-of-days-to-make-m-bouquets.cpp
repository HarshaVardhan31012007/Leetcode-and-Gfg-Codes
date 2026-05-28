class Solution {
public:
    bool possible(vector<int>&bloomDay,int m,int k,int mid){
        int n=bloomDay.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                c++;
                if(c==k){
                    c=0;
                    m--;
                    if(m==0) return true;
                }
            }
            else
            c=0;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n/k<m) return -1;
        int s=*min_element(bloomDay.begin(),bloomDay.end());
        int e=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(bloomDay,m,k,mid)){
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