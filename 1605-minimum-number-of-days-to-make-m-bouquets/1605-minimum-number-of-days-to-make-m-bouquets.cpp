class Solution {
public:
    bool canMakeBouquet(vector<int>&bloomDay,int m,int k,int D){
        int n=bloomDay.size();
        int counter=0;
        for(int i=0;i<n;i++){

        if(bloomDay[i]<=D)
          counter++;
        
        if(counter==k){
            m--;
            counter=0;
            if(m==0) break;
        }
        if(bloomDay[i]>D)
        counter=0;

        }
        return m==0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int s=*min_element(bloomDay.begin(),bloomDay.end());
        int e=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            int day=mid;
            if(canMakeBouquet(bloomDay,m,k,day)){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
};