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




    // int maximumEnergy(vector<int>& energy, int k) {
    //     int ans=INT_MIN;
    //     unordered_map<int,int>mpp;
    //     for(int i=0;i<energy.size();i++){
    //          int idx=i%k;
    //          mpp[idx]=max(mpp[idx]+energy[i],energy[i]);
    //          if(i+k>=energy.size())
    //          ans=max(ans,mpp[idx]);
    //     }
    //     return ans;
    // }


    //  int maximumEnergy(vector<int>& energy, int k) {
    //     vector<int>dp(k,0);
    //     int ans=INT_MIN;
    //     for(int i=0;i<energy.size();i++){
    //          int idx=i%k;
    //          dp[idx]=max(dp[idx]+energy[i],energy[i]);
    //          if(i+k>=energy.size())
    //          ans=max(ans,dp[idx]);
    //     }
    //     return ans;
    // }
   

    int maximumEnergy(vector<int>& energy, int k) {
       int ans=INT_MIN;
       for(int i=energy.size()-k;i<energy.size();i++){
           int sum=0;
           for(int j=i;j>=0;j=j-k){
             sum+=energy[j];
             ans=max(ans,sum);
           }
       }
       return ans;
    }
    
};