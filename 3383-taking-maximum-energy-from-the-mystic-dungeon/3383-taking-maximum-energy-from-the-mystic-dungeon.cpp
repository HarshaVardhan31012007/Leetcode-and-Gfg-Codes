class Solution {
public:
    // int solve(vector<int>&energy,int i,int k){
    //     int j=i;
    //     int sum=0;
    //     while(j+k<energy.size()){
    //         sum+=energy[j+k];
    //         j=j+k;
    //     }
    //     return sum;
    // }
    // int maximumEnergy(vector<int>& energy, int k) {
    //     int ans=INT_MIN;
    //     for(int i=0;i<energy.size();i++){
    //          ans=max(ans,energy[i]+solve(energy,i,k));
    //     }
    //     return ans;
    // }




    int maximumEnergy(vector<int>& energy, int k) {
        int ans=INT_MIN;
        unordered_map<int,int>mpp;
        for(int i=0;i<energy.size();i++){
             int idx=i%k;
             mpp[idx]=max(mpp[idx]+energy[i],energy[i]);
             if(i+k>=energy.size())
             ans=max(ans,mpp[idx]);
        }
        return ans;
    }




};