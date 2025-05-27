// User function Template for C++

class Solution {
  public:
    bool possible(vector<int>&stalls,int mid,int k){
        int c=1;
        int lastpos=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-lastpos>=mid){
                c++;
                if(c==k)
                return true;
                lastpos=stalls[i];
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(),stalls.end());//so that minimum distance will be from consecutive cows.
        int s=0;
        int e=stalls[stalls.size()-1]-stalls[0];
        int ans=0;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(stalls,mid,k)){
                ans=mid;
                s=mid+1;
            }
            else
            e=mid-1;
        }
        return ans;
    }
};