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
    //     vector<int>dp(energy.size(),0);
    //     int ans=INT_MIN;
    //     for(int i=0;i<energy.size();i++){
    //          dp[i]=max((i-k>=0?dp[i-k]:0)+energy[i],energy[i]);
    //          if(i+k>=energy.size())
    //          ans=max(ans,dp[i]);
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
   

    // int maximumEnergy(vector<int>& energy, int k) {
    //    int ans=INT_MIN;
    //    for(int i=energy.size()-k;i<energy.size();i++){
    //        int sum=0;
    //        for(int j=i;j>=0;j=j-k){
    //          sum+=energy[j];
    //          ans=max(ans,sum);
    //        }
    //    }
    //    return ans;
    //}
    

    //Rec+mem

    // int solve(vector<int>&energy,vector<int>&t,int k,int i){
    //     if(i>=energy.size()) return 0;
    //     if(t[i]!=-1) return t[i];
    //     return t[i]=energy[i]+solve(energy,t,k,i+k);
    // }
    // int maximumEnergy(vector<int>& energy, int k) {
    //     vector<int>t(energy.size(),-1);
    //     for(int i=0;i<energy.size();i++){
    //         solve(energy,t,k,i);
    //     }
    //     return *max_element(t.begin(),t.end());
    // }


    
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int>t(energy.size(),-1);
        for(int i=energy.size()-1;i>=0;i--){
            if(i+k<energy.size())
            t[i]=energy[i]+t[i+k];
            else
            t[i]=energy[i];
        }
        return *max_element(t.begin(),t.end());
    }
};