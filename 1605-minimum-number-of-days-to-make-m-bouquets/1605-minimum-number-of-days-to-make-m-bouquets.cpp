class Solution {
public:
    bool possible(int mid,vector<int>&bloomDay,int m,int k){
        int i=0;int count=0;
        while(i<bloomDay.size()){
            if(bloomDay[i]<=mid)
            count++;
            else
            count=0;
            if(count==k) {
                m--;
                count=0;
                if(m==0) break;
            }
            i++;
        }
        return m==0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       // if(m*k>bloomDay.size()) return -1;
        int s=*min_element(bloomDay.begin(),bloomDay.end());
        int e=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(mid,bloomDay,m,k)){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
};