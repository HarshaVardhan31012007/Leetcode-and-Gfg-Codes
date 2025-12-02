class Solution {
public:
    bool possible(vector<int>& position, int m,int mid){
       int last=position[0];
       m--;
       for(int i=1;i<position.size();i++){
            if(position[i]-last>=mid){
                m--;
                if(m==0)
                return true;
                last=position[i];
            }
       }
       return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int s=1;
        int e=position[position.size()-1]-position[0];
        int ans=1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(possible(position,m,mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};